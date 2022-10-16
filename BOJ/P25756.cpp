#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    double ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ans = (100 - (100 - ans) * (100 - a) / 100);
        cout.precision(10);
        cout << ans << '\n';
    }

    return 0;
}