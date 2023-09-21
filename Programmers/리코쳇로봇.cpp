#include <string>
#include <vector>
#include <queue>

using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
int sy, sx;
int ey, ex;
int Y, X;
bool visited[100][100];
int answer = -1;

bool collision_check(int y, int x, const vector<string>& board) {
    if (y < 0 || Y <= y)
        return false;
    if (x < 0 || X <= x)
        return false;
    if (board[y][x] == 'D')
        return false;
    return true;
}

void bfs(const vector<string>& board) {
    queue<pair<int, int>> q;
    q.push({sy, sx});

    int cnt = 0;
    while (!q.empty()) {
        int q_size = q.size();
        for (int i = 0; i < q_size; i++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            if (visited[y][x])
                continue;
            visited[y][x] = true;

            if (y == ey && x == ex) {
                answer = cnt;
                return;
            }

            for (int j = 0; j < 4; j++) {
                int ny = y;
                int nx = x;
                while (collision_check(ny + dy[j], nx + dx[j], board)) {
                    ny += dy[j];
                    nx += dx[j];
                }
                if (!visited[ny][nx])
                    q.push({ny, nx});
            }
        }
        cnt++;
    }
}

int solution(vector<string> board) {
    Y = board.size();
    X = board[0].length();
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            if (board[i][j] == 'R') {
                sy = i;
                sx = j;
            } else if (board[i][j] == 'G') {
                ey = i;
                ex = j;
            }
        }
    }
    bfs(board);

    return answer;
}