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

const int MAXN = 1e6+100;
int k, n, ans;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> k;
    while (k--) {
        cin >> n;
        int it = 0;
        ans = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x == it+1) {
                it = x;
            } else {
                ans++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
