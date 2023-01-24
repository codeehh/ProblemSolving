#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    bool win[1001];
    win[1] = true;
    win[2] = false;
    win[3] = true;
    for (int i = 4; i <= n; i++) {
        win[i] = !(win[i - 1] && win[i - 3]);
    }
    cout << (win[n] ? "SK" : "CY");

    return 0;
}