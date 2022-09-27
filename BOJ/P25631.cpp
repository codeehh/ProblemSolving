#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int ans = 1;
    int cont = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            ans = max(ans, ++cont);
        } else {
            cont = 1;
        }
    }
    cout << ans;

    return 0;
}