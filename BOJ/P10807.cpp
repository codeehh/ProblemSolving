#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[100];

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int v;
    cin >> v;

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == v)
            ans++;

    cout << ans;

    return 0;
}