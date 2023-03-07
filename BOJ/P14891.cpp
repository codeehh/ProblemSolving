#include <iostream>
using namespace std;

void rotate(string& g, int rotateDir) {
    if (rotateDir == 1) {
        char temp = g[7];
        for (int i = 7; i >= 1; i--) {
            g[i] = g[i - 1];
        }
        g[0] = temp;
    } else {
        char temp = g[0];
        for (int i = 0; i < 7; i++) {
            g[i] = g[i + 1];
        }
        g[7] = temp;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string g[5];
    cin >> g[1] >> g[2] >> g[3] >> g[4];
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        int link[5] = {0};
        for (int j = 2; j <= 4; j++) {
            if (g[j - 1][2] != g[j][6]) {
                link[j] = link[j - 1];
            } else {
                link[j] = link[j - 1] + 1;
            }
        }
        for (int j = 1; j <= 4; j++) {
            if (link[j] == link[a]) {
                if (abs(j - a) % 2 == 0) {
                    rotate(g[j], b);
                } else {
                    rotate(g[j], -b);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 4; i++) {
        if (g[i][0] == '1') {
            ans += (1 << (i - 1));
        }
    }
    cout << ans;

    return 0;
}