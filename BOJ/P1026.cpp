#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int A[50], B[50];

    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];

    sort(B, B + n);
    sort(A, A + n, greater<>());

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += (A[i] * B[i]);
    cout << ans;
    return 0;
}