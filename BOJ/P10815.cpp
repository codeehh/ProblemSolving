#include <iostream>
using namespace std;

bool have[20000001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        have[a + 10000000] = true;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        if (have[a + 10000000])
            cout << "1 ";
        else
            cout << "0 ";
    }
    return 0;
}