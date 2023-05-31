#include <iostream>
using namespace std;

int A[100][100];
int B[100][100];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    cin >> m >> k;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int sum = 0;
            for (int h = 0; h < m; h++) {
                sum += (A[i][h] * B[h][j]);
            }
            cout << sum << " ";
        }
        cout << "\n";
    }

    return 0;
}