#include <iostream>
#include <queue>
using namespace std;

const int dr[4] = {1, -1, 0, 0};
const int dc[4] = {0, 0, 1, -1};

int n, m;

int board[500][500];
bool visited[500][500];

int bfs(int r, int c) {
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({r, c});
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        if (visited[cr][cc])
            continue;
        visited[cr][cc] = true;
        cnt++;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (0 <= nr && nr < n && 0 <= nc && nc < m && !visited[nr][nc] && board[nr][nc] == 1)
                q.push({nr, nc});
        }
    }
    return cnt;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    int cnt = 0, maxArea = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && board[i][j] == 1) {
                cnt++;
                maxArea = max(maxArea, bfs(i, j));
            }
        }
    }
    cout << cnt << "\n"
         << maxArea;
    return 0;
}