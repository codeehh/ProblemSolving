#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;
    int d;
    cin >> d;

    int time = a * 60 * 60 + b * 60 + c + d;

    int ans[3];
    ans[2] = time % 60;
    time -= time % 60;
    ans[1] = (time % (60 * 60)) / 60;
    time -= time % (60 * 60);
    ans[0] = time % (24 * 60 * 60) / (60 * 60);
    time -= time % (24 * 60 * 60);

    cout << ans[0] << " " << ans[1] << " " << ans[2];
    return 0;
}