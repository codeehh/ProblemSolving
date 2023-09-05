#include <iostream>
#include <unordered_set>
using namespace std;

char board[1000][1000];
bool visited[1000][1000];
int n, m;
int ans;

class UF {
   public:
    pair<int, int> link[1000][1000];

   public:
    UF() {
        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 1000; j++) {
                link[i][j] = {i, j};
            }
        }
    }

    pair<int, int> find(int r, int c) {
        int nr = link[r][c].first;
        int nc = link[r][c].second;
        if (r == nr && c == nc) {
            return link[r][c];
        }
        return link[r][c] = find(nr, nc);
    }

    void unite(pair<int, int> a, pair<int, int> b) {
        auto ap = find(a.first, a.second);
        auto bp = find(b.first, b.second);
        if (ap != bp) {
            link[ap.first][ap.second] = bp;
            ans--;
        }
    }
};

UF uf;

void dfs(int r, int c) {
    if (visited[r][c])
        return;
    visited[r][c] = true;
    char dir = board[r][c];
    if (dir == 'U' && r > 0) {
        uf.unite({r, c}, {r - 1, c});
        dfs(r - 1, c);
    } else if (dir == 'D' && r < n - 1) {
        uf.unite({r, c}, {r + 1, c});
        dfs(r + 1, c);
    } else if (dir == 'L' && c > 0) {
        uf.unite({r, c}, {r, c - 1});
        dfs(r, c - 1);
    } else if (dir == 'R' && c < m - 1) {
        uf.unite({r, c}, {r, c + 1});
        dfs(r, c + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    ans = n * m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
            }
        }
    }

    cout << ans;

    return 0;
}