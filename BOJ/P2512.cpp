#include <iostream>
using namespace std;

int n, m;
int arr[100000];

bool satisfy(int num) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > num) {
            sum += num;
        } else {
            sum += arr[i];
        }
    }
    return sum <= m;
}

int binarySearch(int lo, int hi) {
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        //조건을 만족하면
        if (satisfy(mid)) {
            lo = mid + 1;
        }
        //조건을 만족하지 않으면
        else {
            hi = mid - 1;
        }
    }
    return hi;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int maxV = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxV = max(maxV, arr[i]);
    }
    cin >> m;
    if (satisfy(100000)) {
        cout << maxV;
    } else {
        cout << binarySearch(0, 1000000000);
    }
    return 0;
}