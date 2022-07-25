#include <iostream>
using namespace std;
const int N = 123456;
bool notPrime[2 * N + 1];

void init() {
    notPrime[1] = true;
    for (int i = 2; i <= N; i++) {
        if (!notPrime[i]) {
            for (int j = i + i; j <= 2 * N; j += i) {
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

    while (true) {
        int n;
        cin >> n;
        if (n == 0)
            break;

        int ans = 0;
        for (int i = n + 1; i <= 2 * n; i++) {
            if (!notPrime[i]) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}