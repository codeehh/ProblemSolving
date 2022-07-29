#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h, m, t;
    cin >> h >> m >> t;

    m += t;
    h += m / 60;
    m %= 60;

    cout << h % 24 << ' ' << m;
    return 0;
}