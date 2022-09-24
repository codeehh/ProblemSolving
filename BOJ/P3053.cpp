#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r;
    cin >> r;

    cout.precision(20);
    cout << atan(1) * 4 * r * r << '\n'
         << 2 * r * r;

    return 0;
}