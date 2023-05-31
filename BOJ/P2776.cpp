#include <iostream>
#include <unordered_set>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;
        unordered_set<int> uset;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            uset.insert(a);
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            if (uset.find(a) == uset.end()) {
                cout << "0\n";
            } else {
                cout << "1\n";
            }
        }
    }

    return 0;
}