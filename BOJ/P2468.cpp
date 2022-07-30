#include <iostream>
#include <set>
using namespace std;
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
int n;
int board[100][100];
bool visited[100][100];
void dfs(int y, int x, int h) {
    if (visited[y][x])
        return;
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (0 <= ny && ny < n && 0 <= nx && nx < n && board[ny][nx] > h && !visited[ny][nx])
            dfs(ny, nx, h);
    }
}

int safeArea(int h) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] > h && !visited[i][j]) {
                ret++;
                dfs(i, j, h);
            }
        }
    }
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    set<int> sett;

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            sett.insert(board[i][j]);
        }
    }

    int ans = 1;
    set<int>::iterator iter;
    for (iter = sett.begin(); iter != sett.end(); iter++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }
        int h = *iter;
        ans = max(ans, safeArea(h));
    }
    cout << ans;
    return 0;
}