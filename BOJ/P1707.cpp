#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin >> k;
    for (int tc = 0; tc < k; tc++) {
        int v, e;
        cin >> v >> e;
        vector<int> adj[20001];
        int color[20001];
        bool visited[20001];
        memset(color, -1, sizeof(color));
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        bool collision = false;
        for (int i = 1; i <= v; i++) {
            if (visited[i])
                continue;
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                if (visited[cur])
                    continue;
                visited[cur] = true;
                for (int next : adj[cur]) {
                    if (color[next] == -1)
                        color[next] = 1 - color[cur];
                    else if (color[next] == color[cur])
                        collision = true;
                    if (!visited[next])
                        q.push(next);
                }
                if (collision)
                    break;
            }
            if (collision)
                break;
        }
        if (collision)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}