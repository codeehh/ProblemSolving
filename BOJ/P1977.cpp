#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n;
    int sum = 0;
    int minV = -1;
    for (int i = 1; i * i <= 10000; i++) {
        int mul = i * i;
        if (m <= mul && mul <= n) {
            sum += mul;
            if (minV == -1) {
                minV = mul;
            }
        }
    }
    if (minV == -1) {
        cout << -1;
    } else {
        cout << sum << "\n"
             << minV;
    }

    return 0;
}