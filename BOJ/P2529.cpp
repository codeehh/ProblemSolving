#include <iostream>
using namespace std;

char arr[9];

int k;
string minAns = "";
string maxAns = "";
bool used[10];

void solve(int idx, string num) {
    if (idx == k) {
        if (minAns == "") {
            minAns = num;
        }
        maxAns = num;
        return;
    }
    char num1 = num.back();
    for (int i = 0; i < 10; i++) {
        if (!used[i]) {
            if ((arr[idx] == '>' && i + '0' < num1) || (arr[idx] == '<' && i + '0' > num1)) {
                used[i] = true;
                solve(idx + 1, num + (char)(i + '0'));
                used[i] = false;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 10; i++) {
        used[i] = true;
        string num = "";
        num += (i + '0');
        solve(0, num);
        used[i] = false;
    }
    cout << maxAns << "\n"
         << minAns;

    return 0;
}