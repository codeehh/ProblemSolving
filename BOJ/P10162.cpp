#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    if (t % 10 != 0)
        cout << -1;
    else {
        cout << t / 300 << " ";
        t %= 300;
        cout << t / 60 << " ";
        t %= 60;
        cout << t / 10;
    }

    return 0;
}