#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    if (n == 1)
        cout << "0";
    else if (n % 2 == 0)
        cout << n * n / 2;
    else
        cout << (n * n - 1) / 2 + 1;

    return 0;
}