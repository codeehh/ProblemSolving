#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;

        int c = a % 10;
        int cnt = 0;
        do {
            a = (a * c) % 10;
            cnt++;
        } while (a != c);
        b %= cnt;

        for (int j = 0; j < b - 1 + cnt; j++) {
            a = (a * c) % 10;
        }
        cout << (a == 0 ? 10 : a) << '\n';
    }

    return 0;
}