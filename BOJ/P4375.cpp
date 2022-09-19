#include <iostream>
using namespace std;

int solve(int n) {
    int a = 1;
    int cnt = 1;
    while (a % n != 0) {
        a %= n;
        a *= 10;
        a++;
        cnt++;
    }
    return cnt;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    while (cin >> n) {
        cout << solve(n) << '\n';
    }

    return 0;
}