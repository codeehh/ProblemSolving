#include <iostream>
using namespace std;

bool isPalindrome[2001][2001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr[2001];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            if (len == 1 || (len == 2 && arr[i] == arr[i + 1]) || (arr[i] == arr[i + len - 1] && isPalindrome[i + 1][i + len - 2]))
                isPalindrome[i][i + len - 1] = true;
        }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        if (isPalindrome[s][e])
            cout << "1\n";
        else
            cout << "0\n";
    }

    return 0;
}