#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string num2;
    cin >> num2;

    string num8 = "";
    for (int i = num2.length() - 1; i >= 0; i -= 3) {
        int sum = 0;
        for (int j = 0; j < 3 && i - j >= 0; j++) {
            sum += (num2[i - j] - '0') * (1 << j);
        }
        num8 += (sum + '0');
    }
    reverse(num8.begin(), num8.end());
    cout << num8;

    return 0;
}