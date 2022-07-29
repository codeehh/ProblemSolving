#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt[7] = {0};
    int maxCnt = 0;
    int number = 0;
    int maxNum = 0;
    for (int i = 0; i < 3; i++) {
        int n;
        cin >> n;
        maxNum = max(maxNum, n);
        cnt[n]++;
        if (maxCnt < cnt[n]) {
            maxCnt = cnt[n];
            number = n;
        }
    }
    if (maxCnt == 3) {
        cout << 10000 + number * 1000;
    } else if (maxCnt == 2) {
        cout << 1000 + number * 100;
    } else if (maxCnt == 1) {
        cout << maxNum * 100;
    }
    return 0;
}