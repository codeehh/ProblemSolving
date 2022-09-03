#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

struct Comp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    }
};

pair<int, int> pos[100000];
set<pair<int, int>, Comp> sett;

int xdist2(pair<int, int> a, pair<int, int> b) {
    return (a.first - b.first) * (a.first - b.first);
}
int dist2(pair<int, int> a, pair<int, int> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pos[i] = {x, y};
    }
    sort(pos, pos + n);

    int ans = dist2(pos[0], pos[1]);
    sett.insert(pos[0]);
    sett.insert(pos[1]);

    int head = 2;
    int tail = 0;
    while (head < n) {
        // head와의 x거리 제곱이 ans보다 크거나 같은 tail 전부 삭제
        while (xdist2(pos[tail], pos[head]) >= ans) {
            sett.erase(pos[tail]);
            tail++;
        }

        // set에 들어있는 원소 중 head와의 y거리가 sqrt(ans)보다 작은 원소만 확인해서 갱신
        int minDist = (int)sqrt(ans) + 1;
        auto iter1 = sett.lower_bound({0, pos[head].second - minDist});
        auto iter2 = sett.upper_bound({0, pos[head].second + minDist});

        while (iter1 != iter2) {
            ans = min(ans, dist2(*iter1, pos[head]));
            iter1++;
        }

        //현재 head set에 삽입
        sett.insert(pos[head++]);
    }

    cout << ans;

    return 0;
}