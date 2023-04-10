#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr[501] = {0};
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr[a] = b;
    }
    vector<int> v;
    for (int i = 1; i <= 500; i++) {
        if (arr[i] != 0) {
            v.push_back(arr[i]);
        }
    }
    int lenToVal[501];
    fill_n(lenToVal, 501, INF);
    lenToVal[1] = v[0];
    int maxLen = 1;
    for (int i = 1; i < v.size(); i++) {
        int len = lower_bound(lenToVal + 1, lenToVal + 1 + maxLen, v[i]) - lenToVal;
        maxLen = max(maxLen, len);
        lenToVal[len] = min(lenToVal[len], v[i]);
    }
    cout << v.size() - maxLen;

    return 0;
}