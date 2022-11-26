#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;

        int cnt = 0;
        while (q.front() != p) {
            q.push(q.front());
            q.pop();
            cnt++;
        }
        ans += min(cnt, (int)q.size() - cnt);
        q.pop();
    }
    cout << ans;
    return 0;
}