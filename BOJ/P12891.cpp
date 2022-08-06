#include <iostream>
using namespace std;

int satisfy(int cnt[], int minCnt[]) {
    for (int i = 0; i < 4; i++) {
        if (cnt[i] < minCnt[i]) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s, p;
    cin >> s >> p;
    string str;
    cin >> str;
    int minCnt[4] = {0};
    for (int i = 0; i < 4; i++)
        cin >> minCnt[i];

    int cnt[4] = {0};
    for (int i = 0; i < p; i++) {
        char c = str[i];
        if (c == 'A') {
            cnt[0]++;
        } else if (c == 'C') {
            cnt[1]++;
        } else if (c == 'G') {
            cnt[2]++;
        } else if (c == 'T') {
            cnt[3]++;
        }
    }

    int ans = 0;
    ans += satisfy(cnt, minCnt);
    for (int i = 1; i < s - p + 1; i++) {
        char c1 = str[i - 1];
        if (c1 == 'A') {
            cnt[0]--;
        } else if (c1 == 'C') {
            cnt[1]--;
        } else if (c1 == 'G') {
            cnt[2]--;
        } else if (c1 == 'T') {
            cnt[3]--;
        }
        char c2 = str[i + p - 1];
        if (c2 == 'A') {
            cnt[0]++;
        } else if (c2 == 'C') {
            cnt[1]++;
        } else if (c2 == 'G') {
            cnt[2]++;
        } else if (c2 == 'T') {
            cnt[3]++;
        }
        ans += satisfy(cnt, minCnt);
    }
    cout << ans;
    return 0;
}