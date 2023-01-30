#include <iostream>
#include <algorithm>
using namespace std;

long long board[1000][1000];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        sort(board[i], board[i] + m);
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += abs(board[i][j] - board[i][(m - 1) / 2]);
        }
    }
    cout << sum << "\n";
    for (int i = 0; i < n; i++) {
        cout << board[i][(m - 1) / 2] << " ";
    }

    return 0;
}