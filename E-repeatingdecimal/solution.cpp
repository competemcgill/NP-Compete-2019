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

ll a,b,c;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (cin >> a >> b >> c) {
        cout << "0.";
        for (int i = 0; i < c; i++) {
            a *= 10;
            ll d = a/b;
            cout << d;
            a -= b*d;
        }
        cout << "\n";
    }

    return 0;
}
