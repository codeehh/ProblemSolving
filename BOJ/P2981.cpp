#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return GCD(b, a % b);
}

priority_queue<int> pq;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    //최대공약수 구하기
    for (int i = 1; i < n; i++) {
        arr[i] -= arr[0];
    }
    int gcd = 0;
    if (n == 2) {
        gcd = arr[1];
    } else {
        gcd = GCD(arr[2], arr[1]);
        for (int i = 3; i < n; i++) {
            gcd = GCD(arr[i], gcd);
        }
    }

    //최대공약수의 약수들 구하기
    for (int i = 1; i * i <= gcd; i++) {
        if (gcd % i == 0) {
            pq.push(-i);
            if (i * i != gcd) {
                pq.push(-gcd / i);
            }
        }
    }
    // 1 제거
    pq.pop();
    while (!pq.empty()) {
        cout << -pq.top() << ' ';
        pq.pop();
    }

    return 0;
}