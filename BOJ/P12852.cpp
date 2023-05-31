#include <iostream>
#include <stack>
using namespace std;

int cache[1000001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = n - 1; i >= 1; i--) {
        cache[i] = cache[i + 1] + 1;
        if (i * 3 <= n) {
            cache[i] = min(cache[i], cache[i * 3] + 1);
        }
        if (i * 2 <= n) {
            cache[i] = min(cache[i], cache[i * 2] + 1);
        }
    }

    cout << cache[1] << "\n";
    int i = 1;
    stack<int> st;
    while (true) {
        st.push(i);
        if (i == n) {
            break;
        }
        if (i * 2 <= n && cache[i * 2] == cache[i] - 1) {
            i *= 2;
        } else if (i * 3 <= n && cache[i * 3] == cache[i] - 1) {
            i *= 3;
        } else if (cache[i + 1] == cache[i] - 1) {
            i++;
        }
    }
    while (st.size()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}