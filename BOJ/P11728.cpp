#include <iostream>
using namespace std;

const int INF = 2000000000;

int A[1000001];
int B[1000001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }
    A[n] = B[m] = INF;
    int p1 = 0, p2 = 0;
    while (p1 < n || p2 < m) {
        if (A[p1] <= B[p2])
            cout << A[p1++] << " ";
        else
            cout << B[p2++] << " ";
    }
    return 0;
}