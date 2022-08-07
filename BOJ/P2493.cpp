#include <iostream>
#include <stack>
using namespace std;

stack<pair<int, int>> stackk;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int h;
        cin >> h;

        bool exist = false;
        while (!stackk.empty()) {
            if (stackk.top().first < h) {
                stackk.pop();
            } else {
                exist = true;
                break;
            }
        }
        if (exist)
            cout << stackk.top().second << ' ';
        else
            cout << 0 << ' ';
        stackk.push({h, i});
    }

    return 0;
}