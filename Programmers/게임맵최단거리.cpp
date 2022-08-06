#include <vector>
#include <queue>
using namespace std;
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

bool visited[100][100];

int solution(vector<vector<int>> maps) {
    int answer = -1;

    int n = maps.size();
    int m = maps[0].size();

    queue<pair<int, int>> q;
    q.push({0, 0});
    int dist = 1;
    while (!q.empty()) {
        int size = q.size();
        bool finish = false;
        for (int i = 0; i < size; i++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            if (y == n - 1 && x == m - 1) {
                answer = dist;
                finish = true;
                break;
            }

            if (visited[y][x])
                continue;
            visited[y][x] = true;

            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (0 <= ny && ny < n && 0 <= nx && nx < m && maps[ny][nx] == 1 && !visited[ny][nx]) {
                    q.push({ny, nx});
                }
            }
        }
        if (finish)
            break;
        dist++;
    }

    return answer;
}