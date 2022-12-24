#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            pq.push(i);
            if (i * i != n)
                pq.push(n / i);
        }
    }
    if (pq.size() < k)
        cout << 0;
    else {
        while (--k) {
            pq.pop();
        }
        cout << pq.top();
    }
    return 0;
}