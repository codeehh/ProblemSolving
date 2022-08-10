#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x;
    cin >> x;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        x -= (a * b);
    }
    if (x == 0)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}