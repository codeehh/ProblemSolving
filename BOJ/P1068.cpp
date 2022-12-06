#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> child[50];
    int parent[50];
    bool deleted[50] = {0};

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        parent[i] = p;
        if (p == -1)
            continue;
        child[p].push_back(i);
    }

    int d;
    cin >> d;

    child[parent[d]].pop_back();

    queue<int> q;
    q.push(d);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        deleted[cur] = true;

        for (int next : child[cur])
            q.push(next);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!deleted[i] && child[i].size() == 0)
            ans++;
    }
    cout << ans;

    return 0;
}