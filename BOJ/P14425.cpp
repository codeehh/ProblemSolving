#include <iostream>
#include <unordered_set>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int ans = 0;
    unordered_set<string> uset;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        uset.insert(str);
    }
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        if (uset.find(str) != uset.end()) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}