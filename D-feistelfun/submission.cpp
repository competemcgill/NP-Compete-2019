/*
   REQUIRED READING: Precomputation solution
   This is the solution we hand in to the judge.
   The program takes the input, looks up our precomputed answer, and outputs it.

	Complexity: O(1)
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
const int INF = 1e9;
const ll INFL = 1LL<<61;
int main() {
	ios::sync_with_stdio(0);cout.precision(20);
	ll m;
	ll bs[40] = {3, 6, 15, 12, 51, 30, 63, 24, 315, 102, 3075, 60, 12291, 126, 255, 48, 65535, 630, 786435, 204, 4095, 6150, 4194303, 120, 17825775, 24582, 436905, 252, 805306371, 510, 1023, 96, 1048575, 131070, 16777215, 1260,206158430211LL, 1572870, 5592405, 408};
	cin >> m;
	cout << bs[m-1] << '\n';
}
