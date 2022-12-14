#include <iostream>
#include <queue>
using namespace std;

const int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int I;
        cin >> I;
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        bool visited[300][300] = {0};
        queue<pair<int, int>> q;
        q.push({y1, x1});
        visited[y1][x1] = true;
        int cnt = 0;
        while (!q.empty()) {
            int qSize = q.size();
            bool arrival = false;
            for (int i = 0; i < qSize; i++) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                if (y == y2 && x == x2) {
                    arrival = true;
                    break;
                }

                for (int d = 0; d < 8; d++) {
                    int ny = y + dy[d];
                    int nx = x + dx[d];
                    if (0 <= ny && ny < I && 0 <= nx && nx < I && !visited[ny][nx]) {
                        q.push({ny, nx});
                        visited[ny][nx] = true;
                    }
                }
            }
            if (arrival)
                break;
            cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}