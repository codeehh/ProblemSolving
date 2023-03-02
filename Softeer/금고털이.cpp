#include <iostream>
#include <queue>
using namespace std;

class Jewelry {
   public:
    int m;
    int p;

    bool operator<(const Jewelry& j) const {
        return p < j.p;
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int w, n;
    cin >> w >> n;
    priority_queue<Jewelry> pq;
    for (int i = 0; i < n; i++) {
        int m, p;
        cin >> m >> p;
        pq.push({m, p});
    }
    long long ans = 0;
    while (!pq.empty()) {
        Jewelry j = pq.top();
        pq.pop();
        if (j.m <= w) {
            ans += (j.m * j.p);
            w -= j.m;
        } else {
            ans += (w * j.p);
            w -= w;
        }
        if (w == 0) {
            break;
        }
    }
    cout << ans;

    return 0;
}