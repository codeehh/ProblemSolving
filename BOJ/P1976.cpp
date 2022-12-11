#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> adj[201];
unordered_set<int> travelPlans;
bool visited[201];

void dfs(int cur) {
    if (visited[cur])
        return;
    visited[cur] = true;

    travelPlans.erase(cur);

    for (int next : adj[cur]) {
        if (!visited[next])
            dfs(next);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int linked;
            cin >> linked;
            if (linked)
                adj[i].push_back(j);
        }
    }
    int travelCity;
    for (int i = 0; i < m; i++) {
        cin >> travelCity;
        travelPlans.insert(travelCity);
    }

    dfs(travelCity);

    cout << (travelPlans.empty() ? "YES" : "NO");

    return 0;
}