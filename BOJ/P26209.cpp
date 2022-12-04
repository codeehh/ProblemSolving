#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char ans = 'S';
    for (int i = 0; i < 8; i++) {
        int input;
        cin >> input;
        if (input == 9) {
            ans = 'F';
            break;
        }
    }
    cout << ans;
    return 0;
}