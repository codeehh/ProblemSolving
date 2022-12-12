#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int snow;
        cin >> snow;
        pq.push(snow);
    }

    int time = 0;
    while (!pq.empty()) {
        int a = pq.top();
        pq.pop();
        if (!pq.empty()) {
            int b = pq.top();
            pq.pop();
            if (b - 1 > 0)
                pq.push(b - 1);
        }
        if (a - 1 > 0)
            pq.push(a - 1);
        time++;
        if (time > 1440) {
            time = -1;
            break;
        }
    }
    cout << time;

    return 0;
}