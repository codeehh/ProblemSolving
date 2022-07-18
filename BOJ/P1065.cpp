#include <iostream>
using namespace std;

int check(int a) {
    if (a < 100)
        return 1;
    int d = a % 10 - (a / 10) % 10;
    a /= 10;
    while (a >= 10) {
        if (d != a % 10 - (a / 10) % 10)
            return 0;
        a /= 10;
    }
    return 1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += check(i);
    }
    printf("%d", ans);
    return 0;
}