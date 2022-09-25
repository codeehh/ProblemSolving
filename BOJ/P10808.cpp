#include <iostream>
using namespace std;

int alphabet[26];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        alphabet[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        cout << alphabet[i] << ' ';
    }

    return 0;
}