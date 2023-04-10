#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int n;
        cin >> n;
        bool inc1[50] = {0};
        bool inc2[50] = {0};
        for (int i = 0; i < n; i++) {
            int cx, cy, r;
            cin >> cx >> cy >> r;
            if ((cx - x1) * (cx - x1) + (cy - y1) * (cy - y1) < r * r) {
                inc1[i] = true;
            }
            if ((cx - x2) * (cx - x2) + (cy - y2) * (cy - y2) < r * r) {
                inc2[i] = true;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!(inc1[i] && inc2[i]) && (inc1[i] || inc2[i])) {
                ans++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}