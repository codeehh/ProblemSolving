#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

pair<int, int> arr[200000];
priority_queue<int, vector<int>, greater<>> pq;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        arr[i] = {s, t};
    }
    sort(arr, arr + n);

    pq.push(arr[0].second);
    for (int i = 1; i < n; i++) {
        if (pq.top() <= arr[i].first)
            pq.pop();
        pq.push(arr[i].second);
    }

    cout << pq.size();

    return 0;
}