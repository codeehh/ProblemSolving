#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        stack<char> st;
        for (int j = 0; j < str.length(); j++) {
            char c = str[j];
            if (st.empty()) {
                st.push(c);
            } else if (st.top() != c) {
                st.push(c);
            } else if (st.top() == c) {
                st.pop();
            }
        }
        if (st.empty()) {
            ans++;
        }
    }
    cout << ans;

    return 0;
}