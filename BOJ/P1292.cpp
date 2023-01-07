#include <iostream>
using namespace std;

int arr[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    int num = 1;
    int p = 1;
    while (p <= b) {
        for (int i = 0; i < num && p <= b; i++) {
            arr[p] = arr[p - 1] + num;
            p++;
        }
        num++;
    }
    cout << arr[b] - arr[a - 1];

    return 0;
}