#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int ans = 0;
    for (int i = 0; i < str.length(); i++) {
        ans *= 16;
        if ('0' <= str[i] && str[i] <= '9') {
            ans += (str[i] - '0');
        } else {
            ans += (str[i] - 'A' + 10);
        }
    }
    cout << ans;

    return 0;
}