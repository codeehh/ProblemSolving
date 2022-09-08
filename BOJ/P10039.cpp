#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sum = 0;
    for (int i = 0; i < 5; i++) {
        int score;
        cin >> score;
        if (score < 40)
            score = 40;
        sum += score;
    }
    cout << sum / 5;

    return 0;
}