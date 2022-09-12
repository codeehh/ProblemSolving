#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long s;
    cin >> s;
    long long a = 1;
    while (a * (a + 1) / 2 <= s) {
        a++;
    }
    cout << a - 1;

    return 0;
}