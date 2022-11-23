#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int e, s, m;
    cin >> e >> s >> m;

    int ans = s;
    while (true) {
        if ((ans - 1) % 15 + 1 == e && (ans - 1) % 19 + 1 == m)
            break;
        ans += 28;
    }
    cout << ans;
    return 0;
}