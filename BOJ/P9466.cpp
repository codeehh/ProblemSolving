#include <iostream>
#include <unordered_set>
#include <cstring>
using namespace std;

int adj[100001];
int status[100001];
unordered_set<int> visited;
int ans;

void init() {
    memset(status, -1, sizeof(status));
}

int dfs(int cur) {
    //저번에 이미 방문했으면
    if (status[cur] != -1) {
        return -1;
    }
    //이번에 이미 방문했으면
    if (visited.find(cur) != visited.end()) {
        return cur;
    }
    visited.insert(cur);
    int join = dfs(adj[cur]);
    //사이클 전부 처리했으면
    if (join == -1) {
        status[cur] = 0;
        ans++;
        return -1;
    }
    //사이클이면
    status[cur] = 1;
    //사이클의 접합부면
    if (join == cur) {
        return -1;
    }
    //사이클의 부분이면
    return join;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        init();
        int n;
        cin >> n;
        for (int j = 1; j <= n; j++) {
            cin >> adj[j];
        }
        ans = 0;
        for (int j = 1; j <= n; j++) {
            if (status[j] == -1) {
                visited.clear();
                dfs(j);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}