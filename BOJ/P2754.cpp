#include <iostream>
using namespace std;

int main(void) {
    string str;
    cin >> str;

    float ans = 0;
    switch (str[0]) {
        case 'A':
            ans += 4;
            break;
        case 'B':
            ans += 3;
            break;
        case 'C':
            ans += 2;
            break;
        case 'D':
            ans += 1;
            break;
    }
    if (str[0] != 'F') {
        switch (str[1]) {
            case '+':
                ans += 0.3;
                break;
            case '-':
                ans -= 0.3;
                break;
        }
    }
    printf("%0.1f", ans);
    return 0;
}