#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> adj[10001];
bool visited[10001];

int dfs(int cur) {
    if (visited[cur])
        return 0;
    visited[cur] = true;

    int ret = 1;
    for (int next : adj[cur]) {
        if (!visited[next])
            ret += dfs(next);
    }

    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    int maxCnt = 0;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        int cnt = dfs(i);
        if (cnt > maxCnt) {
            maxCnt = cnt;
            ans.clear();
            ans.push_back(i);
        } else if (cnt == maxCnt) {
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());

    for (int a : ans)
        cout << a << ' ';

    return 0;
}