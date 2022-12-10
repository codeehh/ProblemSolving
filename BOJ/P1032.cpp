#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    string fileName;
    cin >> fileName;
    for (int i = 1; i < n; i++) {
        string compare;
        cin >> compare;
        for (int j = 0; j < fileName.length(); j++) {
            if (fileName[j] != compare[j]) {
                fileName[j] = '?';
            }
        }
    }
    cout << fileName;
    return 0;
}