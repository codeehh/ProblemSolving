#include <iostream>
#include <queue>
using namespace std;
queue<int> q;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int back;
    for (int i = 0; i < n; i++) {
        string comm;
        cin >> comm;
        if (comm == "push") {
            int num;
            cin >> num;
            q.push(num);
            back = num;
        } else if (comm == "pop") {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if (comm == "size") {
            cout << q.size() << '\n';
        } else if (comm == "empty") {
            if (q.empty()) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else if (comm == "front") {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << q.front() << '\n';
            }
        } else if (comm == "back") {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << back << '\n';
            }
        }
    }

    return 0;
}