#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string hanoi[101];

string cal(string number) {
    reverse(number.begin(), number.end());
    int carry = 1;
    for (int i = 0; i < number.length(); i++) {
        int temp = (number[i] - '0') * 2 + carry;
        number[i] = (temp % 10 + '0');
        carry = temp / 10;
    }
    if (carry)
        number += (carry + '0');
    reverse(number.begin(), number.end());
    return number;
}

void init() {
    hanoi[1] = "1";
    for (int i = 2; i <= 100; i++) {
        hanoi[i] = cal(hanoi[i - 1]);
    }
}

void solve(int n, int from, int through, int to) {
    if (n == 1) {
        cout << from << " " << to << "\n";
        return;
    }
    solve(n - 1, from, to, through);
    cout << from << " " << to << "\n";
    solve(n - 1, through, from, to);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    init();
    cout << hanoi[n] << "\n";
    if (n <= 20) {
        solve(n, 1, 2, 3);
    }

    return 0;
}