#include <iostream>
#include <queue>
using namespace std;
const int dr[4] = {1, -1, 0, 0};
const int dc[4] = {0, 0, 1, -1};

int m, n, k;

bool board[100][100];

int dfs(int r, int c) {
    board[r][c] = 1;
    int ret = 1;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 <= nr && nr < m && 0 <= nc && nc < n && board[nr][nc] == 0)
            ret += dfs(nr, nc);
    }
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int r = y1; r < y2; r++) {
            for (int c = x1; c < x2; c++) {
                board[r][c] = 1;
            }
        }
    }

    int cnt = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) {
                pq.push(dfs(i, j));
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}