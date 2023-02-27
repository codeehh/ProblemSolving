#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int cache[31] = {0};
    if (n % 2 == 1) {
        cout << 0;
    } else {
        cache[2] = 3;
        for (int i = 4; i <= 30; i += 2) {
            cache[i] = 2;
            cache[i] += (cache[i - 2] * 3);
            for (int j = 4; i - j >= 2; j += 2) {
                cache[i] += (cache[i - j] * 2);
            }
        }
        cout << cache[n];
    }

    return 0;
}