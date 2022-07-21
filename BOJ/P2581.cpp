#include <iostream>
using namespace std;

bool notPrime[10001];

void init() {
    notPrime[1] = true;
    for (int i = 2; i <= 5000; i++) {
        if (!notPrime[i]) {
            for (int j = i + i; j <= 10000; j += i) {
                notPrime[j] = true;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    int m, n;
    cin >> m >> n;

    int sum = 0;
    int minV = 10000;
    for (int i = m; i <= n; i++) {
        if (!notPrime[i]) {
            sum += i;
            minV = min(minV, i);
        }
    }
    if (sum != 0)
        cout << sum << "\n"
             << minV;
    else
        cout << "-1";
    return 0;
}