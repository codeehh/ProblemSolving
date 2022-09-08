#include <iostream>
using namespace std;

const int Month[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string Day[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y;
    cin >> x >> y;

    int sum = 0;
    for (int i = 1; i < x; i++) {
        sum += Month[i];
    }
    sum += y - 1;
    cout << Day[sum % 7];

    return 0;
}