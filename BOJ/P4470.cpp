#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    string t;
    getline(cin, t);
    for (int i = 1; i <= n; i++) {
        string str;
        getline(cin, str);
        cout << i << ". " << str << "\n";
    }

    return 0;
}