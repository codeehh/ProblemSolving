#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r1, s;
    cin >> r1 >> s;
    cout << s * 2 - r1;

    return 0;
}