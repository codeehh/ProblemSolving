#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 1000000007;

vector<string> v;

int solve(int depth, int lo, int hi) {
    if (lo == hi)
        return 1;
    long long ret = 1;
    int cnt = 0;
    int prev = lo;
    int cur = prev;
    for (int j = lo + 1; j <= hi; j++) {
        cur = j;
        if (v[cur].length() <= depth) {
            ret = (ret * solve(depth + 1, prev, cur - 1) % M);
            ret = (ret * (++cnt) % M);
            while (j + 1 <= hi && v[j + 1].length() <= depth) {
                j++;
            }
            prev = j + 1;
        } else if (v[prev][depth] != v[cur][depth]) {
            ret *= solve(depth + 1, prev, cur - 1);
            ret %= M;
            ret *= (++cnt);
            ret %= M;
            prev = cur;
        }
    }
    if (prev <= cur) {
        ret *= solve(depth + 1, prev, cur);
        ret %= M;
        ret *= (++cnt);
        ret %= M;
    }
    return (int)ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        v.push_back(name);
    }
    sort(v.begin(), v.end());
    cout << solve(0, 0, v.size() - 1);

    return 0;
}