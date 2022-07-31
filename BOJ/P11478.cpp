#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<string> uset;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    for (int len = 1; len <= str.length(); len++) {
        for (int start = 0; start <= str.length() - len; start++) {
            uset.insert(str.substr(start, len));
        }
    }
    cout << uset.size();
    return 0;
}