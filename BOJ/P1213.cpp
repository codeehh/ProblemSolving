#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int cnt[26] = {0};
    for (int i = 0; i < str.length(); i++) {
        cnt[str[i] - 'A']++;
    }
    int oddCnt = 0;
    char odd;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1) {
            oddCnt++;
            odd = 'A' + i;
        }
    }
    if (oddCnt > 1)
        cout << "I'm Sorry Hansoo";
    else {
        string ans = "";
        for (int i = 0; i < 26; i++) {
            while (cnt[i] >= 2) {
                ans += ('A' + i);
                cnt[i] -= 2;
            }
        }
        if (oddCnt == 1) {
            ans += odd;
            for (int i = ans.length() - 2; i >= 0; i--) {
                ans += ans[i];
            }
        } else {
            for (int i = ans.length() - 1; i >= 0; i--) {
                ans += ans[i];
            }
        }
        cout << ans;
    }

    return 0;
}