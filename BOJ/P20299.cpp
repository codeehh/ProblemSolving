#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, l;
    cin >> n >> k >> l;
    int cnt = 0;
    vector<int> ratings;
    for (int i = 0; i < n; i++) {
        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;
        if (x1 + x2 + x3 >= k && x1 >= l && x2 >= l && x3 >= l) {
            cnt++;
            ratings.push_back(x1);
            ratings.push_back(x2);
            ratings.push_back(x3);
        }
    }
    cout << cnt << '\n';
    for (int rating : ratings) {
        cout << rating << ' ';
    }
    return 0;
}