#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int h = 10;
    char shape = str[0];
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == shape) {
            h += 5;
        } else {
            h += 10;
            shape = str[i];
        }
    }
    cout << h;

    return 0;
}