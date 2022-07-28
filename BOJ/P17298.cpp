#include <iostream>
#include <stack>
using namespace std;

int arr[1000000];
int ans[1000000];
stack<pair<int, int>> stk;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++) {
        while (!stk.empty() && stk.top().first < arr[i]) {
            ans[stk.top().second] = arr[i];
            stk.pop();
        }
        stk.push({arr[i], i});
    }
    while (!stk.empty()) {
        ans[stk.top().second] = -1;
        stk.pop();
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    return 0;
}