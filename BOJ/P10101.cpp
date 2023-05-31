#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;
    if (a + b + c != 180) {
        cout << "Error";
    } else if (a == 60 && b == 60 && c == 60) {
        cout << "Equilateral";
    } else if (a == b || b == c || c == a) {
        cout << "Isosceles";
    } else {
        cout << "Scalene";
    }

    return 0;
}