#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> v;
map<int, int> mapp;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mapp[a]++;
    }
    map<int, int>::iterator iter;
    for (iter = mapp.begin(); iter != mapp.end(); iter++) {
        v.push_back(iter->first);
    }
    int x;
    cin >> x;

    int p1 = 0;
    int p2 = mapp.size() - 1;

    int ans = 0;
    while (p1 < p2) {
        int sum = v[p1] + v[p2];
        if (sum == x) {
            ans += mapp[v[p1]] * mapp[v[p2]];
            p2--;
        } else if (sum > x) {
            p2--;
        } else if (sum < x) {
            p1++;
        }
    }
    cout << ans;
    return 0;
}