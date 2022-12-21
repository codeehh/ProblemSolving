#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    string str;
    cin >> str;
    int cntS = 0;
    int cntB = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 's') {
            cntS++;
            i += 7;
        } else if (str[i] == 'b') {
            cntB++;
            i += 6;
        }
    }

    if (cntS == cntB)
        cout << "bigdata? security!";
    else if (cntS > cntB)
        cout << "security!";
    else if (cntS < cntB)
        cout << "bigdata?";

    return 0;
}