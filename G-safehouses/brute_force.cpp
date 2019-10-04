#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LSOne(i) ((i) & -(i))

const int MAXN = 110;
const int INF = 1e9;
int n, ans;
char m[MAXN][MAXN];

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }

    vii S, H;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] == 'H')
                H.pb({i,j});
            else if (m[i][j] == 'S')
                S.pb({i,j});
        }
    }

    for (ii u : S) {
        int cur = INF;
        for (ii v : H) {
            cur = min(cur, abs(u.fi-v.fi)+abs(u.se-v.se));
        }
        ans = max(ans, cur);
    }

    cout << ans << endl;

    return 0;
}
