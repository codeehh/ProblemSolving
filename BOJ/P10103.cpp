#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int A = 100, B = 100;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a < b)
            A -= b;
        else if (a > b)
            B -= a;
    }
    cout << A << "\n"
         << B;
    return 0;
}