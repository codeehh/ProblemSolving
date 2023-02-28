#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v[4];
    vector<int> t[4];
    int n;
    cin >> n;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            v[i].push_back(a);
            if (i == 2) {
                v[3].push_back(v[0][j] + v[1][j] + v[2][j]);
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        t[i] = v[i];
        sort(t[i].begin(), t[i].end());
        for (int j = 0; j < n; j++) {
            cout << (t[i].end() - upper_bound(t[i].begin(), t[i].end(), v[i][j])) + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}