#include <iostream>
#include <map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    map<int, pair<string, int>> mapp;
    for (int i = 0; i < N; i++) {
        string S;
        int I, D;
        cin >> S >> I >> D;
        mapp.insert({I, {S, D}});
    }
    string ans = "";
    for (auto val : mapp) {
        char c = val.second.first[val.second.second - 1];
        c = ('a' <= c && c <= 'z' ? c - 'a' + 'A' : c);
        ans.push_back(c);
    }
    cout << ans;
    return 0;
}