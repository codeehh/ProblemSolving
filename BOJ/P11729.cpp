#include <iostream>
using namespace std;

void move(int n, int from, int by, int to) {
    if (n == 1) {
        cout << from << ' ' << to << '\n';
        return;
    }
    move(n - 1, from, to, by);
    move(1, from, -1, to);
    move(n - 1, by, from, to);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cout << (1 << n) - 1 << '\n';
    move(n, 1, 2, 3);

    return 0;
}