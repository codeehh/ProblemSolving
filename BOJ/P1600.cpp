#include <iostream>
#include <queue>
using namespace std;
const int INF = 987654321;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
const int horseY[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int horseX[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int k, w, h;
int board[200][200];
int cache[200][200][31];

int solve() {
    if (w == 1 && h == 1) {
        return 0;
    }
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});

    int cnt = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto cur = q.front();
            int y = cur.first.first;
            int x = cur.first.second;
            int use = cur.second;
            q.pop();
            if (cache[y][x][use] != 0) {
                continue;
            }
            cache[y][x][use] = cnt;

            for (int j = 0; j < 4; j++) {
                int ny = y + dy[j];
                int nx = x + dx[j];
                if (0 <= ny && ny < h && 0 <= nx && nx < w && board[ny][nx] == 0 && cache[ny][nx][use] == 0) {
                    q.push({{ny, nx}, use});
                }
            }
            for (int j = 0; j < 8; j++) {
                int ny = y + horseY[j];
                int nx = x + horseX[j];
                if (0 <= ny && ny < h && 0 <= nx && nx < w && board[ny][nx] == 0 && use + 1 <= k && cache[ny][nx][use + 1] == 0) {
                    q.push({{ny, nx}, use + 1});
                }
            }
        }
        cnt++;
    }

    int ret = INF;
    for (int i = 0; i <= k; i++) {
        if (cache[h - 1][w - 1][i] != 0) {
            ret = min(ret, cache[h - 1][w - 1][i]);
        }
    }
    return ret == INF ? -1 : ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> board[i][j];
        }
    }

    cout << solve();

    return 0;
}