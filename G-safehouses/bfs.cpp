/*
 * For each spy, we can simply find manually their distance from a safe house
 * Inserting all the spies into a grid, we run BFS for every spy and find the nearest safe house
 * Complexity: O(n^4) (O(n^2) spies, O(n^2) BFS) but O(n^3) in practice
 *
 * BONUS: There is an O(n^2) solution. Can you find it?
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
//h: grid of safehouse locations
//dist: grid of distances from a spy
//dx/dy: Hard coded directions (right,up,left,down)
//s: list of spy locations
bool h[200][200];
int dist[110][110];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vii s;
int main() {
	ios::sync_with_stdio(0);cout.precision(20);
	int n;
	cin >> n;
	//Insert spies and safehouses into the grid/list of spies
	for(int i=0;i<n;i++) {
		string st;
		cin >> st;
		for(int j=0;j<n;j++) {
			if(st[j] == 'H') {h[i][j] = true;} else {h[i][j] = false;}
			if(st[j] == 'S') {s.push_back(mp(i,j));}
		}
	}
	//Initialize max distance
	int md = 0;
	//For every spy, run the BFS and update max distance
	for(int i=0;i<s.size();i++) {
		ii sc = s[i];
		int r = sc.first,c = sc.second;
		memset(dist,-1,sizeof(dist));
		dist[r][c] = 0;
		queue<ii> qi;
		qi.push(mp(r,c));
		while(1) {
			ii co = qi.front();qi.pop();
			int r = co.first,c = co.second;
			bool fd = false;
			for(int j=0;j<4;j++) {
				int u = r+dx[j];
				int v = c+dy[j];
				if(u < 0 || u >= n) continue;
				if(v < 0 || v >= n) continue;
				if(dist[u][v] != -1) {continue;}
				dist[u][v] = dist[r][c]+1;
				if(h[u][v]) {md = max(md,dist[u][v]);fd = true;break;}
				qi.push(mp(u,v));
			}
			if(fd) break;
		}
	}
	//Output max distance to safehouse
	cout << md << '\n';
}
