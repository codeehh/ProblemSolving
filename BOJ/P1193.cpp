#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x;
    cin >> x;

    int sum = 0;
    int add = 1;
    while (sum + add < x) {
        sum += (add++);
    }
    if (add % 2 == 0)
        cout << x - sum << "/" << add + 1 - (x - sum);
    else
        cout << add + 1 - (x - sum) << "/" << x - sum;

    return 0;
}