#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        int ans = 0;
        string str;
        getline(cin, str);
        if (str == "#")
            break;
        for (int i = 0; i < str.length(); i++) {
            char c = str[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}