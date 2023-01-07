#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans[2] = {0, 100000};
    for (int i = 0; i < 7; i++) {
        int a;
        cin >> a;
        if (a % 2 == 1) {
            ans[0] += a;
            ans[1] = min(ans[1], a);
        }
    }
    if (ans[0] == 0) {
        cout << -1;
    } else {
        cout << ans[0] << "\n"
             << ans[1];
    }

    return 0;
}