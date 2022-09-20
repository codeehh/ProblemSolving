#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        pq.push(-num);
    }
    for (int i = 0; i < k - 1; i++) {
        pq.pop();
    }
    cout << -pq.top();
    return 0;
}