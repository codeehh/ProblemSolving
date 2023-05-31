#include <iostream>
#include <unordered_map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    unordered_map<string, int> mapp;
    int maxCnt = 0;
    string ans = "";
    for (int i = 0; i < n; i++) {
        string bookName;
        cin >> bookName;
        mapp[bookName]++;
        if (mapp[bookName] == maxCnt && bookName < ans) {
            ans = bookName;
        } else if (mapp[bookName] > maxCnt) {
            maxCnt = mapp[bookName];
            ans = bookName;
        }
    }
    cout << ans;

    return 0;
}