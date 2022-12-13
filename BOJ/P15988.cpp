#include <iostream>
#include <cstring>
using namespace std;

int cache[1000001];
const int M = 1000000009;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;
    for (int j = 4; j <= 1000000; j++) {
        cache[j] = (cache[j] + cache[j - 1]) % M;
        cache[j] = (cache[j] + cache[j - 2]) % M;
        cache[j] = (cache[j] + cache[j - 3]) % M;
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << cache[n] << "\n";
    }

    return 0;
}