#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[6] = {1, 1, 2, 2, 2, 8};
    for (int i = 0; i < 6; i++) {
        int num;
        cin >> num;
        cout << arr[i] - num << ' ';
    }

    return 0;
}