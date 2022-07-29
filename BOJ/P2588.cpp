#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    cout << a * (b % 10) << '\n'
         << a * (b / 10 % 10) << '\n'
         << a * (b / 100 % 10) << '\n'
         << a * b;

    return 0;
}