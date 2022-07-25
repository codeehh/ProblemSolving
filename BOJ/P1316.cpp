#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        int used[26] = {0};
        used[str[0] - 'a'] = 1;
        bool cnt = true;
        for (int j = 1; j < str.length(); j++) {
            if (str[j] != str[j - 1]) {
                if (used[str[j] - 'a'] == 1) {
                    cnt = false;
                    break;
                }
                used[str[j] - 'a'] = 1;
            }
        }
        if (cnt)
            ans++;
    }
    cout << ans;
    return 0;
}