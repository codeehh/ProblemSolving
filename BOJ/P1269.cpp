#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> A, B;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    int ans = 0;
    for (int i = 0; i < a; i++) {
        int num;
        cin >> num;
        A.insert(num);
    }
    for (int i = 0; i < b; i++) {
        int num;
        cin >> num;
        B.insert(num);
        if (A.find(num) != A.end()) {
            ans++;
        }
    }

    cout << a + b - 2 * ans;
    return 0;
}