#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int ans = 1;
    for (int i = 2; i <= n; i++) {
        ans *= i;
    }

    cout << ans;

    return 0;
}