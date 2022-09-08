#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (!cin.eof()) {
        string str;
        getline(cin, str);
        cout << str << '\n';
    }

    return 0;
}