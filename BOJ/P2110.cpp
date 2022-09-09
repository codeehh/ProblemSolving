#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

bool solve(int interval, int n, int c) {
    int cur = v[0];
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] - cur >= interval) {
            cur = v[i];
            cnt++;
        }
    }
    if (cnt >= c)
        return true;
    return false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    int lo = 1;
    int hi = v[v.size() - 1] - v[0];
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (solve(mid, n, c))
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    cout << hi;

    return 0;
}