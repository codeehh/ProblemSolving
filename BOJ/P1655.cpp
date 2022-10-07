#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    if (n == 1) {
        int a;
        cin >> a;
        cout << a;
        return 0;
    }

    priority_queue<int> pqMax;
    priority_queue<int, vector<int>, greater<int>> pqMin;
    int a, b;
    cin >> a >> b;
    cout << a << "\n";
    cout << min(a, b) << "\n";
    pqMax.push(min(a, b));
    pqMin.push(max(a, b));
    for (int i = 2; i < n; i++) {
        int c;
        cin >> c;
        if (pqMax.size() == pqMin.size()) {
            if (c <= pqMin.top()) {
                pqMax.push(c);
                cout << pqMax.top() << "\n";
            } else {
                pqMin.push(c);
                cout << pqMin.top() << "\n";
            }
        } else if (pqMax.size() < pqMin.size()) {
            if (c <= pqMin.top()) {
                pqMax.push(c);
            } else {
                pqMax.push(pqMin.top());
                pqMin.pop();
                pqMin.push(c);
            }
            cout << pqMax.top() << "\n";
        } else if (pqMax.size() > pqMin.size()) {
            if (c >= pqMax.top()) {
                pqMin.push(c);
            } else {
                pqMin.push(pqMax.top());
                pqMax.pop();
                pqMax.push(c);
            }
            cout << pqMax.top() << "\n";
        }
    }

    return 0;
}