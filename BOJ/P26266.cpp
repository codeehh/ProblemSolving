#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<>> getDivisors(int len) {
    priority_queue<int, vector<int>, greater<>> divisors;
    for (int i = 1; i * i <= len; i++) {
        if (len % i == 0) {
            divisors.push(i);
            divisors.push(len / i);
        }
    }
    return divisors;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string plain, cryptograph;
    cin >> plain >> cryptograph;

    int len = plain.length();

    for (int i = 0; i < len; i++) {
        cryptograph[i] -= plain[i] - 'A' + 1;
        if (cryptograph[i] - 'A' + 1 < 1)
            cryptograph[i] += 26;
    }

    priority_queue<int, vector<int>, greater<>> divisors = getDivisors(len);

    while (!divisors.empty()) {
        int patLen = divisors.top();
        divisors.pop();
        string pat = cryptograph.substr(0, patLen);
        bool findPat = true;
        for (int i = patLen; i < len; i += patLen) {
            if (cryptograph.substr(i, patLen) != pat) {
                findPat = false;
                break;
            }
        }
        if (findPat) {
            cout << pat;
            break;
        }
    }

    return 0;
}