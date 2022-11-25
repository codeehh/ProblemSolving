#include <iostream>
#include <cstring>
using namespace std;

int n;

int board[100][100];
long long cache[100][100];

long long solve(int r, int c) {
    if (r == n - 1 && c == n - 1)
        return 1;
    if (board[r][c] == 0)
        return 0;

    long long& ret = cache[r][c];
    if (ret != -1)
        return ret;

    ret = 0;
    int jump = board[r][c];
    if (r + jump < n)
        ret += solve(r + jump, c);
    if (c + jump < n)
        ret += solve(r, c + jump);
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(cache, -1, sizeof(cache));

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    solve(0, 0);
    cout << cache[0][0];
    return 0;
}