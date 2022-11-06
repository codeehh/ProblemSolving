#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char start;
    cin >> start;

    string str = "ILOVEYONSEI";

    int ans = 0;
    ans += abs(start - 'I');
    for (int i = 0; i < str.length() - 1; i++) {
        ans += abs(str[i] - str[i + 1]);
    }
    cout << ans;
    return 0;
}