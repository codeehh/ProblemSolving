#include <iostream>
using namespace std;

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return GCD(b, a % b);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int ring1;
    cin >> ring1;
    for (int i = 1; i < n; i++) {
        int ring;
        cin >> ring;
        int gcd = GCD(ring1, ring);
        cout << ring1 / gcd << "/" << ring / gcd << "\n";
    }

    return 0;
}