#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int ans;
    cin >> ans;
    int sum = ans;
    for (int i = 1; i < n; i++) {
        int num;
        cin >> num;
        sum = max(sum, 0) + num;
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}