#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

char board[1000][1000];
bool visited[1000][1000];
int link_size[1000][1000];
int cnt_arr[1000][1000];
int n, m;
int cnt = 1;

void bfs(int r, int c) {
    int sizee = 0;
    queue<pair<int, int>> temp;
    queue<pair<int, int>> q;
    q.push({r, c});
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (visited[y][x])
            continue;
        visited[y][x] = true;
        temp.push({y, x});
        sizee++;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (0 <= ny && ny < n && 0 <= nx && nx < m && board[ny][nx] == '0' && !visited[ny][nx]) {
                q.push({ny, nx});
            }
        }
    }
    while (!temp.empty()) {
        int y = temp.front().first;
        int x = temp.front().second;
        temp.pop();
        link_size[y][x] = sizee;
        cnt_arr[y][x] = cnt;
    }
    cnt++;
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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '0' && !visited[i][j]) {
                bfs(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '1') {
                int sum = 1;
                unordered_set<int> cnt_set;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dy[k];
                    int nj = j + dx[k];
                    if (0 <= ni && ni < n && 0 <= nj && nj < m && board[ni][nj] == '0') {
                        if (cnt_set.find(cnt_arr[ni][nj]) == cnt_set.end()) {
                            cnt_set.insert(cnt_arr[ni][nj]);
                            sum += link_size[ni][nj];
                        }
                    }
                }
                cout << (sum % 10);
            } else {
                cout << "0";
            }
        }
        cout << "\n";
    }

    return 0;
}