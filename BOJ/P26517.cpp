#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin >> k;
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if ((long long)a * k + b == (long long)c * k + d)
        cout << "Yes " << (long long)a * k + b;
    else
        cout << "No";

    return 0;
}