#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        string str;
        getline(cin, str);
        if (str == "")
            break;
        int a = 0, b = 0, c = 0, d = 0;
        for (int i = 0; i < str.length(); i++) {
            char cc = str[i];
            if ('a' <= cc && cc <= 'z') {
                a++;
            } else if ('A' <= cc && cc <= 'Z') {
                b++;
            } else if ('0' <= cc && cc <= '9') {
                c++;
            } else if (cc == ' ') {
                d++;
            }
        }
        cout << a << " " << b << " " << c << " " << d << "\n";
    }

    return 0;
}