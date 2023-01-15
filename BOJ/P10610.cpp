#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int cnt[10] = {0};
    int sum = 0;
    for (int i = 0; i < str.length(); i++) {
        int num = str[i] - '0';
        cnt[num]++;
        sum += num;
    }
    if (cnt[0] == 0 || sum % 3 != 0) {
        cout << -1;
    } else {
        string ans = "";
        for (int i = 9; i >= 0; i--) {
            while (cnt[i]--) {
                ans += (i + '0');
            }
        }
        cout << ans;
    }

    return 0;
}