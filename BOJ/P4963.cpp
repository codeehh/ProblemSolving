#include <iostream>
#include <cstring>
using namespace std;

const int dy[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int w, h;

int board[50][50];
bool visited[50][50];

void dfs(int y, int x) {
    visited[y][x] = true;
    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (0 <= ny && ny < h && 0 <= nx && nx < w && board[ny][nx] == 1 && !visited[ny][nx]) {
            dfs(ny, nx);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> board[i][j];
            }
        }
        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
        memset(visited, 0, sizeof(visited));
    }

    return 0;
}