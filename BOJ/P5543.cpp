#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int burger = 2000;
    for (int i = 0; i < 3; i++) {
        int a;
        cin >> a;
        burger = min(burger, a);
    }
    int beverage = 2000;
    for (int i = 0; i < 2; i++) {
        int a;
        cin >> a;
        beverage = min(beverage, a);
    }
    cout << burger + beverage - 50;
    return 0;
}