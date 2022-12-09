#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[100001];
bool visited[100001];
int order[100001];

int cnt = 1;

void dfs(int cur) {
    if (visited[cur])
        return;
    visited[cur] = true;

    order[cur] = cnt++;

    for (int next : adj[cur]) {
        if (!visited[next])
            dfs(next);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, r;
    cin >> n >> m >> r;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(r);

    for (int i = 1; i <= n; i++) {
        cout << order[i] << "\n";
    }

    return 0;
}