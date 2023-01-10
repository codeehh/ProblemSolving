#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        int a;
        cin >> a;
        ans += min(n, a);
    }
    cout << ans;

    return 0;
}