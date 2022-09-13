#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string num1, num2;
    cin >> num1 >> num2;

    int p1 = num1.length() - 1;
    int p2 = num2.length() - 1;

    vector<int> ans;
    int carry = 0;
    while (!(p1 < 0 && p2 < 0)) {
        int sum = carry;
        if (p1 >= 0)
            sum += (num1[p1--] - '0');
        if (p2 >= 0)
            sum += (num2[p2--] - '0');

        if (sum >= 10)
            carry = 1;
        else
            carry = 0;

        ans.push_back(sum % 10);
    }
    if (carry)
        ans.push_back(1);

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }

    return 0;
}