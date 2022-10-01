#include <iostream>
using namespace std;

int k;
int arr[12];
int sel[6];

void comb(int idx, int sidx) {
    if (sidx == 6) {
        for (int i = 0; i < 6; i++) {
            cout << sel[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = idx; i <= k - 6 + sidx; i++) {
        sel[sidx] = arr[i];
        comb(i + 1, sidx + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> k;
        if (k == 0) {
            break;
        }
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }
        comb(0, 0);
        cout << '\n';
    }

    return 0;
}