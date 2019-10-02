/*
 * REQUIRED READING: The precomputation answer

   For those who really don't want to precompute, there is a solution to calculate the answer live, but the time saved
   by avoiding precomputation is easily lost by having to solve and optimize the solution (remember the 1 second time limit)

   This will be solved with meet-in-the-middle, where at the start of the program we calculate some "known states" for the 
   two matrices to end up in and "jump ahead" by calculating how the two matrices will look thousands of rounds in the future.
 	
   The approach is similar in nature to the "Baby-step Giant-step" algorithm
	Complexity: O(m^2*sqrt(MAX_N)log(MAX_N))
	with MAX_N the size of the largest solution (which is about 2*10^11)

	This solution can be made about 2x faster with unordered_maps and custom hashes,
   	but that introduces even more programming issues
 */
#include <bits/stdc++.h>
#define MD 1000000007
#define MF 998244353
#define fore(b,c) for(int val0=b;val0<c;val0++)
#define forr(k,c,s) for(int k=c;k<s;k++)
#define pb push_back
#define mp make_pair
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long double ld;
typedef vector<vii> al;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
const int INF = 1e9;
const ll INFL = 1LL<<61;
//We will precompute up to 2^19 different future states and jump ahead 2^19 rounds to save time
const ll PRE = 1LL<<19;
typedef pair<pl,pl> sa;
//Map from states to how far they are from the start state
map<sa,ll> mm;
ll m;
const sa bg = mp(mp(1,0),mp(0,1));
//Runs one feistel block as before
sa op(sa stt) {
	pl x = stt.first,y = stt.second;
	ll md = (1LL<<m) - 1;
	pl t = {y.first<<1,y.second<<1};
	if(t.first > md) {t.first = (t.first&md) + 1;}
	if(t.second > md) {t.second = (t.second&md) + 1;}
	pl ret = {x.first^t.first,x.second^t.second};
	return mp(y,ret);
}
//Multiplies a state by M^ro
sa rol(sa st, ll ro) {
	if(ro > m) {ro %= m;}
	for(int i=0;i<2;i++) {
		pl& p = (i==0?st.first:st.second);
		for(int j=0;j<2;j++) {
			ll& q = (j==0?p.first:p.second);
			ll ls = q>>(m-ro);
			ll rs = (q&((1LL<<(m-ro))-1)) << ro;
			q = rs|ls;
		}
	}
	return st;
}
/*
   A vector containing the answer to the following question:
   If we ran the feistel block PRE times on a state just containing (X,1) or (1,X) or (Y,1) or (1,Y),
   What would the resulting state look like?
   The i'th element of the vector contains the answer for (X*M^i,1) or (1,X*M^1), etc.

   We can use this to do the "jump ahead" process and save time running the feistel block
 */
vector<sa> gs[2][2];
ll pre() {
	//Initialize the first elements to (X,1),(Y,1),(1,X), and (1,Y), respectively
	for(int i=0;i<m;i++) {
		gs[0][0].push_back({{1LL<<i,0},{0,0}});
		gs[0][1].push_back({{0,1LL<<i},{0,0}});
		gs[1][0].push_back({{0,0},{1LL<<i,0}});
		gs[1][1].push_back({{0,0},{0,1LL<<i}});
	}
	sa rv = bg;
	//Then, run the feistel block on the values PRE times, with 2 purposes:
	//Fill in our table of "seen" states for when we jump ahead,
	//And fill in the jump ahead states
	for(int i=0;i<PRE;i++) {
		//If we happen to get back to the beginning (i.e. the cipher loops in less then PRE rounds), return that now
		if(mm.find(rv) != mm.end()) return i;
		mm[rv] = i;
		rv = op(rv);
		for(int re=0;re<2;re++) {
			for(int cy=0;cy<2;cy++) {
				gs[re][cy][0] = op(gs[re][cy][0]);
			}
		}
	}
	//Note that value for (X*M^i,1) and similar ones are just the answer for (X,1) times M^i, since
	//The feistel block does not treat powers of M differently modulo m.
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			for(int k=1;k<m;k++) {
				gs[i][j][k] = rol(gs[i][j][0],k);
			}
		}
	}
	return -1;
}
/*
   Runs the feistel block cipher PRE times using just O(m) steps using our precomputed vectors

   We do this by using our precomputed answers to how (1,X), (X,1), etc. map after being shuffled PRE times
   and xor them together according to whether they appeared in the initial state.
   Because of the properties of xor, this will exactly be the state after running the block cipher PRE times.
 */
sa lop(sa st) {
	sa res = {{0,0},{0,0}};
	//Go through both the left & right sides
	for(int re=0;re<2;re++) {
		//p focuses on just that side
		pl& p = (re == 0?st.first:st.second);
		//For each of the m places,
		for(int i=0;i<m;i++) {
			//If the i'th element of the left/right size has X*M^i in its xor,
			//xor the result by how it would be after PRE blocks
			if(p.first & (1LL<<i)) {
				res.first.first ^= gs[re][0][i].first.first;
				res.first.second ^= gs[re][0][i].first.second;
				res.second.first ^= gs[re][0][i].second.first;
				res.second.second ^= gs[re][0][i].second.second;
			}
			//Do the same if Y*M^i is in the xor
			if(p.second & (1LL<<i)) {
				res.first.first ^= gs[re][1][i].first.first;
				res.first.second ^= gs[re][1][i].first.second;
				res.second.first ^= gs[re][1][i].second.first;
				res.second.second ^= gs[re][1][i].second.second;
			}
		}
	}
	return res;
}
int main() {
	cin >> m;
	//Run our preparation code
	ll val = pre();
	//If the block loops early, return it
	if(val != -1) {
		cout << val << '\n';
		return 0;
	}
	ll tot = 0;
	sa st = bg;
	//Otherwise, keep running our accelerated block cipher until it matches a state we have already seen
	while(1) {
		st = lop(st);
		tot += PRE;
		//If we have seen the state, adjust our loop count and return
		if(mm.find(st) != mm.end()) {
			tot -= mm[st];
			break;
		}
	}
	cout << tot << '\n';
	return 0;
}
