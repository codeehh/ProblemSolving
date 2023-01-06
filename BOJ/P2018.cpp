#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int cnt = 0;
    int num = 1;
    while (true) {
        int sum = num * (num + 1) / 2;
        if (sum > n)
            break;
        if ((n - sum) % num == 0)
            cnt++;
        num++;
    }
    cout << cnt;

    return 0;
}