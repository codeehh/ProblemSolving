#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
int sel[8];

void Comb(int idx, int sidx) {
    if (sidx == m) {
        for (int i = 0; i < m; i++) {
            cout << sel[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = idx; i < n; i++) {
        sel[sidx] = arr[i];
        Comb(i + 1, sidx + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    Comb(0, 0);

    return 0;
}