#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    int ans = 0;
    int depth = -1;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            depth++;
        } else if (str[i] == ')') {
            if (str[i - 1] == '(') {
                ans += depth;
            } else if (str[i - 1] == ')') {
                ans++;
            }
            depth--;
        }
    }
    cout << ans;

    return 0;
}