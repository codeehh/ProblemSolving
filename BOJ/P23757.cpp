#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        pq.push(c);
    }
    int ans = 1;
    for (int i = 0; i < m; i++) {
        int w;
        cin >> w;
        if (pq.top() < w) {
            ans = 0;
            break;
        }
        int rest = pq.top() - w;
        pq.pop();
        if (rest != 0)
            pq.push(rest);
    }
    cout << ans;

    return 0;
}