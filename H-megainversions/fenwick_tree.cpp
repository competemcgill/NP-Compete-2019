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

const int MAXN = 1e5+100;
ll n, ans, a[MAXN];
vector<vector<ll>> ft (3, vector<ll> (MAXN, 0));

void update (vector<ll>& v, ll idx, ll val) {
    for (; idx < MAXN; idx += LSOne(idx))
        v[idx] += val;
}

ll query (vector<ll>& v, ll idx) {
    ll res = 0;
    for (; idx; idx -= LSOne(idx))
        res += v[idx];
    return res;
}

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    reverse(a,a+n);
    for (ll i = 0; i < n; i++) {
        update(ft[0],a[i],1);
        update(ft[1],a[i],query(ft[0],a[i]-1));
        update(ft[2],a[i],query(ft[1],a[i]-1));
    }

    cout << query(ft[2],n) << endl;

    return 0;
}
