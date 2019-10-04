/*
   There are two exceptionally hard problems on NP-Compete this year: Megainversions (this problem) and Feistel Fun.
   This is the second hardest problem because of the relatively obscure data structures required to solve it.

   The question is asking for triplets of decreasing integers on a given array.
   In order to count this number, we also keep track of decreasing "singlets" of numbers
   and decreasing doubles of numbers with the least number being n.

   We then go through the array one by one:
   Each integer always ends off one singlet (itself) and ends off
   many pairs (x,y) where y is our number and x was a singlet greater than y seen before.
   Each number also ends off many triplets (x,y,z) where (x,y) was a pair ended off by y seen before.
   Note that to count triplets we don't ever need to know x, just how many pairs that ended in y.

   To simplify even further, we essentially have 3 arrays of size N, where, whenever we see a new number x:
   array 1 is incremented by 1 @ x
   array 2 @ x is incremented by the sum of all values greater than x in array 1
   array 3 @ x is incremented by the sum of all values greater than x in array 2

   However, we cannot simply sum over these arrays, because that takes O(N) time for a O(N^2) solution, which will TLE.
   Instead, we use segment trees to use O(log N) time per sum, giving O(N log N) time.

   This problem somewhat resembles a DP problem from summer training, but the O(N^2) solution from that problem
   can't be applied here, since N = 10^5.

   The segment trees we use are not the implementation used in Competitive Programming 3 (Chapter 2.4.3), but rather the one described here:
   https://codeforces.com/blog/entry/18051
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 100100;
ll st[3][2*MN];
ll w[MN];
int n;
//Updates the segment tree number [id] by adding [val] to index [p]
void up(int p, ll val, int id) {
	for(p+=n;p>0;p>>=1) {
		st[id][p] += val;
	}
}
//Queries for the sum of the elements in [l,r) on the segment tree number [id]
ll qu(int l, int r, int id) {
	ll res = 0;
	for(l += n,r += n;l<r;l>>=1,r>>=1) {
		if(l&1) {
			res += st[id][l++];
		}
		if(r&1) {
			res += st[id][--r];
		}
	}
	return res;
}
int main() {
	memset(st,0,sizeof(st));
	scanf("%d ",&n);
	//Go through the n elements of the array:
	for(int i=0;i<n;i++) {
		scanf("%d ",&w[i]);
		w[i]--;
		//Add 1 to the first array
		up(w[i],1,0);
		//Then, for the other 2 arrays,
		//Add to this array the sum of all values greater than w[i] in the previous array
		for(int j=1;j<3;j++) {
			up(w[i],qu(w[i]+1,n,j-1),j);
		}
	}
	//Then, add all the triplets in array 3 to get the final answer
	printf("%lld\n",qu(0,n,2));
}
