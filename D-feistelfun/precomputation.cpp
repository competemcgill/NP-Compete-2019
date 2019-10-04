/*
   This problem is the hardest on NP-Compete because it is difficult to even understand and
   the solutions that work are highly unconventional.

   This solution is the "easier" of the two solutions but requires a bit of meta-thinking on how the problem can be solved.
   In particular, notice that the problem only asks for a solution for 1 <= m <= 40.
   That means that this program could only possibly receive 40 different inputs.

   Rather than try to solve the problem in the 1 second time limit, we could just pre-solve the problem for all 40 inputs
   and hand in an array containing all 40 possible answers.

   This code is some unoptimized solution that has no hope of solving the biggest inputs in 1 second but solves all 40 inputs
   about 10 minutes.
   In particular, it runs in O(MAX_N) time (MAX_N is the size of the largest answer, which turns out to be ~2*10^11).
   However, our "time limit" isn't 1 second but however much time is left in the contest, so it is "fast enough".

   Annotations below:
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
typedef pair<pl,pl> sa;
map<pl,pl> ma;
ll m;
/*We can represent X and Y using 2 pairs of 2 64-bit integers, where in each pair:
  The first integer represents the contribution to that value by X and its i'th powers, where
  the i'th bit of the integer being on indicates that X*M^i is xor'ed into that value
  The second integer is the same, but for Y

  The first pair represents the left side, and the second pair represents the right
 */
//The value "bg" represents the starting state, where X and Y are unchanged.
//Hence, the 1st value on the left is just X (X*M^0)
//and the 2nd value on the right is just Y.
const sa bg = mp(mp(1,0),mp(0,1));
/*
   The function "op" runs the feistel block cipher once on a state representing a left and right half
 */
sa op(sa stt) {
	pl x = stt.first,y = stt.second;
	ll md = (1LL<<m) - 1;
	//Multiplying Y by M effectively shifts all the bits in Y to the right 1 place...
	pl t = {y.first<<1,y.second<<1};
	//But M^m is 1, so we have to take it off the end and put it back in as 1
	if(t.first > md) {t.first = (t.first&md) + 1;}
	if(t.second > md) {t.second = (t.second&md) + 1;}
	//Then, xor the left half with this modified right half and swap before returning
	pl ret = {x.first^t.first,x.second^t.second};
	return mp(y,ret);
}
int main() {
	//Loops through all 40 possible inputs and returns the solution for each one
	for(m = 1;m<=40;m++) {
		sa rl = bg;
		ll ct = 1;
		rl = op(rl);
		//While the mapping is still not the identity, run the block another time
		while(rl != bg) {
			rl = op(rl);
			ct++;
		}
		cout << ct << '\n';
	}
}
