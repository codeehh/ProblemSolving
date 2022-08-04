#include <iostream>
using namespace std;

int arr[11];
int oper[4];
int n;
int maxx = -1000000000;
int minn = 1000000000;

void solve(int idx, int result) {
    if (idx == n) {
        maxx = max(maxx, result);
        minn = min(minn, result);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (oper[i] != 0) {
            oper[i]--;
            if (i == 0) {
                solve(idx + 1, result + arr[idx]);
            } else if (i == 1) {
                solve(idx + 1, result - arr[idx]);
            } else if (i == 2) {
                solve(idx + 1, result * arr[idx]);
            } else if (i == 3) {
                solve(idx + 1, result / arr[idx]);
            }
            oper[i]++;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < 4; i++)
        cin >> oper[i];

    solve(1, arr[0]);

    cout << maxx << '\n'
         << minn;
    return 0;
}