#include <iostream>
#include <string>
using namespace std;

string s;

void reverseWord(int sIdx, int eIdx) {
    if (sIdx > eIdx)
        return;
    for (int i = 0; i <= (eIdx - sIdx) / 2; i++) {
        swap(s[sIdx + i], s[eIdx - i]);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, s);
    bool inTag = false;
    int sIdx = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '<') {
            reverseWord(sIdx, i - 1);
            inTag = true;
            continue;
        } else if (s[i] == '>') {
            inTag = false;
            sIdx = i + 1;
            continue;
        }
        if (inTag) {
            continue;
        }
        if (s[i] == ' ') {
            reverseWord(sIdx, i - 1);
            sIdx = i + 1;
        }
        if (i == s.length() - 1) {
            reverseWord(sIdx, i);
        }
    }
    cout << s;
    return 0;
}