#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    stack<char> st;
    int ans = 0;
    int mul = 1;
    bool add = false;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == '(') {
            st.push(c);
            mul *= 2;
            add = true;
        } else if (c == ')') {
            if (st.empty() || st.top() != '(') {
                ans = 0;
                break;
            }
            st.pop();
            if (add)
                ans += mul;
            mul /= 2;
            add = false;
        } else if (c == '[') {
            st.push(c);
            mul *= 3;
            add = true;
        } else if (c == ']') {
            if (st.empty() || st.top() != '[') {
                ans = 0;
                break;
            }
            st.pop();
            if (add)
                ans += mul;
            mul /= 3;
            add = false;
        }
    }
    if (!st.empty())
        ans = 0;
    cout << ans;

    return 0;
}