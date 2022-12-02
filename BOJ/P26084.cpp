#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char, int> nameCnt;
unordered_map<char, int> teamNameCnt;

long long Comb(long long n, int m) {
    if (m == 1)
        return n;
    else if (m == 2)
        return n * (n - 1) / 2;
    else
        return n * (n - 1) * (n - 2) / 6;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string teamName;
    cin >> teamName;
    for (int i = 0; i < teamName.length(); i++) {
        teamNameCnt[teamName[i]]++;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        nameCnt[name[0]]++;
    }
    long long ans = 1;
    for (auto a : teamNameCnt) {
        ans *= Comb(nameCnt[a.first], a.second);
    }
    cout << ans;
    return 0;
}