#include <iostream>
using namespace std;

bool notPrime[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    bool finish = false;
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (!notPrime[i]) {
            for (int j = i; j <= n; j += i) {
                if (!notPrime[j]) {
                    notPrime[j] = true;
                    if (--k == 0) {
                        ans = j;
                        finish = true;
                        break;
                    }
                }
            }
        }
        if (finish) {
            break;
        }
    }
    cout << ans;

    return 0;
}