#include <iostream>
#include <unordered_set>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string list[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    unordered_set<string> uset;
    for (int i = 0; i < 8; i++)
        uset.insert(list[i]);

    string str;
    cin >> str;

    int ans = 0;
    for (int i = 0; i < str.length(); i++) {
        for (int j = 0; j < 8; j++) {
            if (i + list[j].length() <= str.length()) {
                if (uset.find(str.substr(i, list[j].length())) != uset.end()) {
                    i += (list[j].length() - 1);
                    break;
                }
            }
        }
        ans++;
    }
    cout << ans;

    return 0;
}