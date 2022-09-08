#include <iostream>
using namespace std;

const int t[26] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int ans = 0;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        ans += t[c - 'A'];
    }

    cout << ans;

    return 0;
}