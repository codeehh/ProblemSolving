#include <iostream>
using namespace std;

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int r, c, d;
    cin >> r >> c >> d;
    int board[50][50];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    int ans = 0;
    while (true) {
        board[r][c] = 2;
        ans++;
        bool breakFlag1 = false;
        bool breakFlag2 = false;
        while (true) {
            for (int i = 0; i < 4; i++) {
                int nd = (d == 0 ? 3 : d - 1);
                int nr = r + dr[nd];
                int nc = c + dc[nd];
                //왼쪽 방향이 영역 내이면
                if (0 <= nr && nr < n && 0 <= nc && nc < m) {
                    //왼쪽 방향이 청소하지 않은 공간이면
                    if (board[nr][nc] == 0) {
                        d = nd;
                        r = nr;
                        c = nc;
                        breakFlag1 = true;
                        break;
                    }
                    //청소할 공간이 아니면
                    d = nd;
                    continue;
                }
            }
            if (breakFlag1)
                break;
            //네 방향 모두 청소가 되어있고
            //뒤가 벽이면
            int nd = (d + 2) % 4;
            int nr = r + dr[nd];
            int nc = c + dc[nd];
            if (0 <= nr && nr < n && 0 <= nc && nc < m && board[nr][nc] == 1) {
                breakFlag2 = true;
                break;
            }
            //뒤가 벽이 아니면
            else {
                r = nr;
                c = nc;
                continue;
            }
        }
        if (breakFlag2)
            break;
    }
    cout << ans;
    return 0;
}