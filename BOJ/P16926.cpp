#include <iostream>
#include <vector>
using namespace std;

int board[300][300];
int result[300][300];

vector<vector<int>> save;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, r;
    cin >> n >> m >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < min(n, m) / 2; i++) {
        vector<int> v;
        for (int x = i; x < m - i; x++)
            v.push_back(board[i][x]);
        for (int y = 1 + i; y < n - i; y++)
            v.push_back(board[y][m - 1 - i]);
        for (int x = m - 2 - i; x >= i; x--)
            v.push_back(board[n - 1 - i][x]);
        for (int y = n - 2 - i; y >= 1 + i; y--)
            v.push_back(board[y][i]);
        save.push_back(v);
    }
    for (int i = 0; i < min(n, m) / 2; i++) {
        vector<int> v = save[i];
        int M = v.size();
        int p = r % M;
        for (int x = i; x < m - i; x++) {
            result[i][x] = v[p];
            p = (p + 1) % M;
        }
        for (int y = 1 + i; y < n - i; y++) {
            result[y][m - 1 - i] = v[p];
            p = (p + 1) % M;
        }
        for (int x = m - 2 - i; x >= i; x--) {
            result[n - 1 - i][x] = v[p];
            p = (p + 1) % M;
        }
        for (int y = n - 2 - i; y >= 1 + i; y--) {
            result[y][i] = v[p];
            p = (p + 1) % M;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}