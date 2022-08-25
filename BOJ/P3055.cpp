#include <iostream>
#include <queue>
using namespace std;
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c;
    cin >> r >> c;

    pair<int, int> house;
    queue<pair<int, int>> dochi;
    queue<pair<int, int>> water;

    char board[50][50];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'D') {
                house.first = i;
                house.second = j;
            } else if (board[i][j] == '*') {
                water.push({i, j});
            } else if (board[i][j] == 'S') {
                dochi.push({i, j});
            }
        }
    }
    bool dochiVisited[50][50] = {0};
    bool waterVisited[50][50] = {0};

    int time = -1;
    while (!dochi.empty() || !water.empty()) {
        int waterSize = water.size();
        for (int i = 0; i < waterSize; i++) {
            int y = water.front().first;
            int x = water.front().second;
            water.pop();

            if (waterVisited[y][x])
                continue;
            waterVisited[y][x] = true;

            board[y][x] = '*';

            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (0 <= ny && ny < r && 0 <= nx && nx < c && !waterVisited[ny][nx] && board[ny][nx] != 'D' && board[ny][nx] != 'X')
                    water.push({ny, nx});
            }
        }
        if (time != -1) {
            int dochiSize = dochi.size();
            for (int i = 0; i < dochiSize; i++) {
                int y = dochi.front().first;
                int x = dochi.front().second;
                dochi.pop();

                if (y == house.first && x == house.second) {
                    cout << time;
                    return 0;
                }

                if (dochiVisited[y][x])
                    continue;
                dochiVisited[y][x] = true;

                for (int d = 0; d < 4; d++) {
                    int ny = y + dy[d];
                    int nx = x + dx[d];
                    if (0 <= ny && ny < r && 0 <= nx && nx < c && !dochiVisited[ny][nx] && (board[ny][nx] == '.' || board[ny][nx] == 'D'))
                        dochi.push({ny, nx});
                }
            }
        }
        time++;
    }
    cout << "KAKTUS";
    return 0;
}