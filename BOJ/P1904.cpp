#include <iostream>
using namespace std;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    if (n <= 2) {
        cout << n;
        return 0;
    }
    int cache1 = 1;
    int cache2 = 2;
    int cache3 = 0;
    for (int i = 3; i <= n; i++) {
        cache3 = (cache1 + cache2) % 15746;
        cache1 = cache2;
        cache2 = cache3;
    }
    cout << cache3;
    return 0;
}