#include <iostream>
using namespace std;

bool notSelfNumber[10036];

int makeSelfNumber(int n) {
    int sum = 0;
    sum += n;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 10000; i++) {
        if (!notSelfNumber[i])
            cout << i << '\n';
        notSelfNumber[makeSelfNumber(i)] = true;
    }
    return 0;
}