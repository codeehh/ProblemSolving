#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int Y = 0, M = 0;
    for (int i = 0; i < n; i++) {
        int callTime;
        cin >> callTime;
        Y += (callTime / 30 + 1) * 10;
        M += (callTime / 60 + 1) * 15;
    }
    if (Y == M) {
        cout << "Y M " << Y;
    } else if (Y < M) {
        cout << "Y " << Y;
    } else if (Y > M) {
        cout << "M " << M;
    }

    return 0;
}