#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char arr[5] = {'D', 'C', 'B', 'A', 'E'};

    for (int i = 0; i < 3; i++) {
        int cnt = 0;
        for (int j = 0; j < 4; j++) {
            int a;
            cin >> a;
            cnt += a;
        }
        cout << arr[cnt] << "\n";
    }

    return 0;
}