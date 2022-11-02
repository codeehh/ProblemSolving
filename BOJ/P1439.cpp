#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int cnt0 = 0;
    int cnt1 = 0;
    int flag = 1 - (str[0] - '0');
    for (int i = 0; i < str.length(); i++) {
        int num = str[i] - '0';
        if (flag != num) {
            if (num == 0) {
                cnt0++;
            } else {
                cnt1++;
            }
            flag = num;
        }
    }
    cout << min(cnt0, cnt1);
    return 0;
}