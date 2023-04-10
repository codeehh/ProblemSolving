#include <iostream>
#include <algorithm>
using namespace std;

int arr[7];
int sel[7];
int n, m;

void solve(int idx) {
    if (idx == m) {
        for (int i = 0; i < m; i++) {
            cout << sel[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        sel[idx] = arr[i];
        solve(idx + 1);
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
    solve(0);

    return 0;
}