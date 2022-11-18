#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[300001];
bool visited[300001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k, x;
    cin >> n >> m >> k >> x;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    queue<int> q;
    q.push(x);
    int dist = 0;
    priority_queue<int, vector<int>, greater<>> ans;
    while (!q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            int cur = q.front();
            q.pop();
            if (visited[cur])
                continue;
            visited[cur] = true;

            if (dist == k)
                ans.push(cur);

            for (int next : adj[cur]) {
                if (!visited[next])
                    q.push(next);
            }
        }
        if ((++dist) > k)
            break;
    }
    if (ans.empty())
        cout << "-1";
    else {
        while (!ans.empty()) {
            cout << ans.top() << "\n";
            ans.pop();
        }
    }

    return 0;
}