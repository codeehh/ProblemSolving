#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string str;
        cin >> str;

        int l = 0;
        int r = str.length() - 1;
        int isPalindrome = 1;
        int cnt = 1;
        while (l < r) {
            cnt++;
            if (str[l] != str[r]) {
                isPalindrome = 0;
                cnt--;
                break;
            }
            l++;
            r--;
        }

        cout << isPalindrome << ' ' << cnt << '\n';
    }

    return 0;
}