#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    if (n == 1 || n == 2) {
        cout << 1;
        return 0;
    }

    int a = 1, b = 1, c;

    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    cout << c;

    return 0;
}