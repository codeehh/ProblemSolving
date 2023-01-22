#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if ('a' <= c && c <= 'z') {
            str[i] = (c - 'a' + 13) % 26 + 'a';
        } else if ('A' <= c && c <= 'Z') {
            str[i] = (c - 'A' + 13) % 26 + 'A';
        }
        cout << str[i];
    }

    return 0;
}