#include <iostream>
using namespace std;

int len(int num) {
    int ret = 0;
    while (num) {
        ret++;
        num /= 10;
    }
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    long long ans = 0;
    int a = 1;
    while (true) {
        if (n >= a * 10) {
            ans += (9 * a * (len(a)));
        } else {
            ans += ((n - a + 1) * len(a));
            break;
        }
        a *= 10;
    }
    cout << ans;

    return 0;
}