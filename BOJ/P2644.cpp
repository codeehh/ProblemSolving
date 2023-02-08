#include <iostream>
#include <cstring>
using namespace std;

int parent[101];
int cntArray[101];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(cntArray, -1, sizeof(cntArray));

    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        parent[y] = x;
    }
    int cnt = 0;
    while (true) {
        cntArray[a] = cnt++;
        a = parent[a];
        if (a == 0)
            break;
    }
    cnt = 0;
    while (true) {
        if (cntArray[b] != -1) {
            cout << cntArray[b] + cnt;
            break;
        }
        b = parent[b];
        if (b == 0) {
            cout << -1;
            break;
        }
        cnt++;
    }

    return 0;
}