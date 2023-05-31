#include <iostream>
using namespace std;

int n;
int ans;

void copy_board(int a[20][20], int b[20][20]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = a[i][j];
        }
    }
}

void push_board(int dir, int board[20][20]) {
    if (dir == 0) {  // 상
        for (int j = 0; j < n; j++) {
            int pre = 0;
            int stack_cnt = 0;
            for (int i = 0; i < n; i++) {
                int cur = board[i][j];
                if (cur == 0)
                    continue;
                board[i][j] = 0;
                if (pre != 0) {
                    if (pre == cur) {
                        board[stack_cnt++][j] = pre * 2;
                        pre = 0;
                        continue;
                    } else
                        board[stack_cnt++][j] = pre;
                }
                pre = cur;
            }
            if (pre != 0)
                board[stack_cnt++][j] = pre;
        }
    } else if (dir == 1) {  // 우
        for (int i = 0; i < n; i++) {
            int pre = 0;
            int stack_cnt = 0;
            for (int j = n - 1; j >= 0; j--) {
                int cur = board[i][j];
                if (cur == 0)
                    continue;
                board[i][j] = 0;
                if (pre != 0) {
                    if (pre == cur) {
                        board[i][n - 1 - (stack_cnt++)] = pre * 2;
                        pre = 0;
                        continue;
                    } else
                        board[i][n - 1 - (stack_cnt++)] = pre;
                }
                pre = cur;
            }
            if (pre != 0)
                board[i][n - 1 - (stack_cnt++)] = pre;
        }
    } else if (dir == 2) {  // 하
        for (int j = 0; j < n; j++) {
            int pre = 0;
            int stack_cnt = 0;
            for (int i = n - 1; i >= 0; i--) {
                int cur = board[i][j];
                if (cur == 0)
                    continue;
                board[i][j] = 0;
                if (pre != 0) {
                    if (pre == cur) {
                        board[n - 1 - (stack_cnt++)][j] = pre * 2;
                        pre = 0;
                        continue;
                    } else
                        board[n - 1 - (stack_cnt++)][j] = pre;
                }
                pre = cur;
            }
            if (pre != 0)
                board[n - 1 - (stack_cnt++)][j] = pre;
        }
    } else if (dir == 3) {  // 좌
        for (int i = 0; i < n; i++) {
            int pre = 0;
            int stack_cnt = 0;
            for (int j = 0; j < n; j++) {
                int cur = board[i][j];
                if (cur == 0)
                    continue;
                board[i][j] = 0;
                if (pre != 0) {
                    if (pre == cur) {
                        board[i][stack_cnt++] = pre * 2;
                        pre = 0;
                        continue;
                    } else
                        board[i][stack_cnt++] = pre;
                }
                pre = cur;
            }
            if (pre != 0)
                board[i][stack_cnt++] = pre;
        }
    }
}

int find_max(int board[20][20]) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ret = max(ret, board[i][j]);
        }
    }
    return ret;
}

void solve(int depth, int board[20][20]) {
    if (depth == 5) {
        ans = max(ans, find_max(board));
        return;
    }
    for (int dir = 0; dir < 4; dir++) {
        int temp_board[20][20];
        copy_board(board, temp_board);
        push_board(dir, temp_board);
        solve(depth + 1, temp_board);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int board[20][20];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    solve(0, board);
    cout << ans;

    return 0;
}