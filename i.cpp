/*
   The problem can be interpreted either as a graph problem (the obvious interpretation)
   or a DP problem (Directed Acyclic Graphs naturally induce dynamic programming)
   As a graph problem, the idea is to "push" forward the paths from one node 
   to all of its children and to make sure it has received all paths from its parents (keeping track of good and bad paths)
   before proceeding.
   As a DP problem, the states/transitions are:
   States: The nodes
   Transitions: The pointers to the next nodes
   Here, for every node we sum the number of paths to reach it from its parents, and summing over both good gates and all gates this way
   (In practice, this involves reversing graph edges but that is easy)
   Complexity O(mn)

   This code is the DP solution to the problem.

   A concern that the keen-eyed observer might see is that the answer
   can explode outside the range of a 64-bit integer with a cleverly made graph
   This does not occur in the test cases, but one should be aware of weird edge cases when solving problems.
 */
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
const int MN = 1100;
//Actual graph and DP states
vvi g;
ll dp[MN];
//DP transition:
ll ds(int u) {
	//If the graph is a starting gate, there is 1 path (the node itself)
	if(g[u].size() == 0) return 1;
	//If the number of paths is known, return it
	if(dp[u] != -1) return dp[u];
	//Otherwise, sum over all the paths from its parents
	ll res = 0;
	for(int i=0;i<g[u].size();i++) {
		res += ds(g[u][i]);
	}
	return dp[u] = res;
}
//2 bitsets:
//gt: Is the given node a good gate?
//ed: Is the given node an ending node?
bitset<MN> gt,ed;
int main() {
	memset(dp,-1,sizeof(dp));
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	g.assign(n,vi());
	ed.set();
	//Get all the edges and:
	while(m--) {
		int a,b;
		scanf("%d %d",&a,&b);
		//Add the (reversed) edge to the graph, and note that a cannot be an end gate
		g[b].push_back(a);
		ed.reset(a);
	}
	int k;scanf("%d",&k);
	//Get all the accepting gates
	while(k--) {
		int t;scanf("%d",&t);
		gt.set(t);
	}
	ll tot = 0,win = 0;
	//Using DP, sum all the winning and total paths and print
	for(int i=0;i<n;i++) {
		if(gt[i]) {
			win += ds(i);
		}
		if(ed[i]) {
			tot += ds(i);
		}
	}
	printf("%s %lld\n%s %lld\n","winning paths",win,"total paths",tot);
}
