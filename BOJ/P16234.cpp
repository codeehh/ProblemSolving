#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

int n, l, r;
int board[50][50];
bool isUnited[50][50];
vector<pair<int, int>> unite;
int uniteSum = 0;

bool isOpened(int y, int x, int ny, int nx) {
    return l <= abs(board[y][x] - board[ny][nx]) && abs(board[y][x] - board[ny][nx]) <= r;
}

void dfs(int y, int x) {
    isUnited[y][x] = true;
    unite.push_back({y, x});
    uniteSum += board[y][x];
    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (0 <= ny && ny < n && 0 <= nx && nx < n && !isUnited[ny][nx] && isOpened(y, x, ny, nx)) {
            dfs(ny, nx);
        }
    }
};

bool isMoved() {
    bool ret = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!isUnited[i][j]) {
                dfs(i, j);
                for (int k = 0; k < unite.size(); k++) {
                    int y = unite[k].first;
                    int x = unite[k].second;
                    board[y][x] = uniteSum / unite.size();
                }
                if (unite.size() > 1) {
                    ret = true;
                }
                unite.clear();
                uniteSum = 0;
            }
        }
    }
    return ret;
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int days = 0;
    while (isMoved()) {
        days++;
        memset(isUnited, 0, sizeof(isUnited));
    }
    cout << days;

    return 0;
}