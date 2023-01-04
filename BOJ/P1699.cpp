#include <iostream>
#include <cmath>
using namespace std;

const int INF = 987654321;

int cache[100001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cache[i] = INF;
        int j = 1;
        while (i - j * j >= 0) {
            cache[i] = min(cache[i], cache[i - j * j] + 1);
            j++;
        }
    }
    cout << cache[n];

    return 0;
}