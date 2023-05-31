#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 2 * n - 1; j++) {
            if (i == n - 1 || j == n - i || j == n + i) {
                cout << "*";
                if (j == n + i) {
                    break;
                }
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}