#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1100;
long long n,m,k, indegree[MAXN];
vector<vector<int>> graph (MAXN);
bitset<MAXN> isGate;
long long winPath[MAXN], totalPath[MAXN];

void dfs (long long cur) {
    long long winCount = isGate[cur];
    long long totalCount = 0;

    if (totalPath[cur] > 0)
        return;

    for (int neighbor : graph[cur]) {
        dfs(neighbor);
        winCount += winPath[neighbor];
        totalCount += totalPath[neighbor];
    }

    winPath[cur] = winCount;
    totalPath[cur] = (totalCount > 0) ? totalCount : 1;
}

int main (void) {
    cin >> n >> m;
    for (int i; i < m; i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }

    cin >> k;
    isGate.reset();
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        isGate[x] = true;
    }

    long long winResult = 0, totalResult = 0;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            dfs(i);
            winResult += winPath[i];
            totalResult += totalPath[i];
        }
    }

    cout << "winning paths " << winResult << "\n";
    cout << "total paths " << totalResult << "\n";
}
