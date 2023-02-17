#include <iostream>
#include <deque>
#include <queue>
using namespace std;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int board[101][101];
deque<pair<int, int>> dq;
queue<pair<int, char>> q;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        board[y][x] = 2;
    }
    int l;
    cin >> l;
    for (int i = 0; i < l; i++) {
        int x;
        char c;
        cin >> x >> c;
        q.push({x, c});
    }

    int time = 0;
    int y = 1, x = 1;
    board[y][x] = 1;
    dq.push_front({y, x});
    int dir = 0;
    while (true) {
        // 이번 time에 방향전환을 하면 방향전환
        if (q.front().first == time) {
            if (q.front().second == 'L') {
                dir = (dir == 0 ? 3 : dir - 1);
            } else {
                dir = (dir + 1) % 4;
            }
            q.pop();
        }

        // 방향대로 진행할 수 있는지 확인
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (!(1 <= ny && ny <= n && 1 <= nx && nx <= n)) {
            break;
        }
        if (board[ny][nx] == 1) {
            break;
        }

        // 진행
        y = ny;
        x = nx;

        // 사과가 없으면 꼬리 줄어들기
        if (board[y][x] == 0) {
            int tailY = dq.back().first;
            int tailX = dq.back().second;
            dq.pop_back();
            board[tailY][tailX] = 0;
        }
        board[y][x] = 1;
        dq.push_front({y, x});

        // time 증가
        time++;
    }
    cout << time + 1;

    return 0;
}