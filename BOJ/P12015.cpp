#include <iostream>
#include <algorithm>
using namespace std;

int idxToMaxLen[1000001];
int lenToMinVal[1000001];

int bs(int lo, int hi, int val) {
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (lenToMinVal[mid] < val)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return hi;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        int maxLen = bs(0, ans, num);
        idxToMaxLen[i] = maxLen + 1;
        if (lenToMinVal[maxLen + 1] == 0)
            lenToMinVal[maxLen + 1] = num;
        else
            lenToMinVal[maxLen + 1] = min(lenToMinVal[maxLen + 1], num);
        ans = max(ans, maxLen + 1);
    }
    cout << ans;
    return 0;
}