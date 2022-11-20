#include <iostream>
#include <cstring>
using namespace std;

int cache[41];

int fib(int n) {
    if (n == 1 || n == 2)
        return 1;
    int& ret = cache[n];
    if (ret != -1)
        return ret;
    return ret = fib(n - 1) + fib(n - 2);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(cache, -1, sizeof(cache));

    int n;
    cin >> n;

    fib(n);

    cout << cache[n] << " " << n - 2;

    return 0;
}