#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int cnt[10] = {0};

    while (n != 0) {
        cnt[n % 10 == 9 ? 6 : n % 10]++;
        n /= 10;
    }
    cnt[6] = (cnt[6] + 1) / 2;
    cout << *max_element(cnt, cnt + 9);

    return 0;
}