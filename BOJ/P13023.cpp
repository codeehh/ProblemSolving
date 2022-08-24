#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;

vector<int> adj[2000];
bool visited[2000];
int found = 0;

void dfs(int cur, int depth) {
    if (depth == 4) {
        found = 1;
        return;
    }
    visited[cur] = true;
    for (int next : adj[cur]) {
        if (found)
            return;
        if (!visited[next])
            dfs(next, depth + 1);
    }
    visited[cur] = false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        dfs(i, 0);
    }
    cout << found;
    return 0;
}