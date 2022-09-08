#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        if (i != 0 && i % 10 == 0)
            cout << '\n';
        cout << str[i];
    }

    return 0;
}