#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if ('a' <= str[i] && str[i] <= 'z') {
            str[i] += ('A' - 'a');
        } else {
            str[i] += ('a' - 'A');
        }
    }
    cout << str;
    return 0;
}