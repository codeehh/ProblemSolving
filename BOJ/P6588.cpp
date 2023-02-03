#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool notPrime[1000001];
vector<int> oddPrime;

void init() {
    notPrime[1] = true;
    for (int i = 2; i <= 1000000; i++) {
        if (!notPrime[i]) {
            if (i % 2 == 1) {
                oddPrime.push_back(i);
            }
            for (int j = i + i; j <= 1000000; j += i) {
                notPrime[j] = true;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    while (true) {
        int n;
        cin >> n;
        if (n == 0)
            break;

        int a = 0;
        auto iter = lower_bound(oddPrime.begin(), oddPrime.end(), n);
        while (iter != oddPrime.begin()) {
            iter--;
            if (n - *iter >= 3 && !notPrime[n - *iter]) {
                a = n - *iter;
                break;
            }
        }

        cout << n << " = " << a << " + " << n - a << "\n";
    }

    return 0;
}