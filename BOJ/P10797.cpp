#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a;
    cin >> a;
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        int b;
        cin >> b;
        if (a == b) {
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}