#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        int prev = 200001;
        for (int j = 0; j < num; j++) {
            int bookNum;
            cin >> bookNum;
            if (prev <= bookNum) {
                cout << "No";
                return 0;
            }
            prev = bookNum;
        }
    }
    cout << "Yes";
    return 0;
}