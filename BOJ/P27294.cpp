#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, s;
    cin >> t >> s;

    if (12 <= t && t <= 16 && s == 0)
        cout << 320;
    else
        cout << 280;

    return 0;
}