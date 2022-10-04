#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0;
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        int out, in;
        cin >> out >> in;
        sum += (in - out);
        ans = max(ans, sum);
    }
    cout << ans;

    return 0;
}