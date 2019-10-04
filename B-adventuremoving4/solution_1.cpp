/*
   This one is a funky dynamic programming problem

   The key to a DP problem is figuring out what the states are, what the transitions are, and whether that's fast enough
   The states are:
   Pairs of (number of station reached, fuel left in car)
   The transitions are:
   Amount you fill up the gas tank at each station (up to full)

   Then, there are 100*200 states and at each state we fill up to 200 literes (only whole numbers) for a time of
   100*200*200 = 4*10^6 operations, which is fast enough

   Thus, we can use this DP formulation
   Complexity (n*m^2), n = # of stations, m = tank capacity
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
//DP states, station distances, and prices
ll dp[110][220];
ll ps[110],di[110];
int ctr=0;
//Top down DP:
ll bs(int id, int f) {
	f -= di[id];
	//If we have no fuel, cost is infinite
	if(f < 0) {return 999999999;}
	if(dp[id][f] != -1) {return dp[id][f];}
	//If we are at the end, either we pay nothing (the tank is at least half full) or we get gouged (cost is infinite)
	if(id == ctr) {return f>=100?0:999999999;}
	ll val = 999999999;
	//Otherwise, fill up the tank however and return the minimum cost + cost of refilling here
	for(int i=0;i<=200-f;i++) {
		val = min(val,ps[id]*i+bs(id+1,f+i));
	}
	//Memoize the answer
	return dp[id][f] = val;
}
int main() {
	int d;
	scanf("%d ",&d);
	int ds,pr;
	memset(dp,-1,sizeof(dp));
	int td = 0;
	while(scanf("%d %d ",&ds,&pr) == 2) {
		ps[ctr] = pr;
		di[ctr] = ds-td;
		td = ds;
		ctr++;
	}
	di[ctr] = d-td;
	ll tot = bs(0,100);
	if(tot > 100000000) {
		printf("Impossible\n");
	} else {
		printf("%lld\n",tot);
	}
}
