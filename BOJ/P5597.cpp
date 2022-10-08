#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool arr[31] = {false};
    for (int i = 0; i < 28; i++) {
        int a;
        cin >> a;
        arr[a] = true;
    }
    for (int i = 1; i <= 30; i++) {
        if (!arr[i]) {
            cout << i << '\n';
        }
    }

    return 0;
}