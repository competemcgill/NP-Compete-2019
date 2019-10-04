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

const ll MAXN = 10100;
const ll INF = 1e18;
ll n, dp[MAXN][210], km, gas;
vector<ll> station (MAXN,INF);

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    while (cin >> km >> gas) {
        station[km] = min(station[km], gas);
    }

    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < 210; j++) {
            dp[i][j] = INF;
        }
    }

    dp[0][100] = 0;
    for (int i = 0; i <= n; i++) {
        int last = -1;
        for (int j = 0; j <= 200; j++) {
            if (i > 0) {
                dp[i][j] = min(dp[i][j], dp[i-1][j+1]);
            }
            if (last == -1 && dp[i][j] < INF) last = j;
        }

        if (last != -1 && station[i] < INF) {
            for (int j = 0; j+last <= 200; j++) {
                if (dp[i][last]+station[i]*j < dp[i][j+last]) {
                    dp[i][j+last] = dp[i][last]+station[i]*j;
                } else {
                    last = j+last;
                    j = 0;
                }
            }
        }
    }

    if (dp[n][100] >= INF) {
        cout << "Impossible";
    } else {
        cout << "\n";
        cout << dp[n][100];
    }
    cout << "\n";

    return 0;
}
