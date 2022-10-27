#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int maxV = -1, maxI, maxJ;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            int input;
            cin >> input;
            if (input > maxV) {
                maxV = input;
                maxI = i;
                maxJ = j;
            }
        }
    }
    cout << maxV << "\n"
         << maxI << " " << maxJ;
    return 0;
}