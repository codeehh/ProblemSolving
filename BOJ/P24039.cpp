#include <iostream>
#include <vector>
using namespace std;

bool notPrime[201];
vector<int> prime;

void init() {
    for (int i = 2; i <= 200; i++) {
        if (!notPrime[i]) {
            prime.push_back(i);
            for (int j = i + i; j <= 200; j += i) {
                notPrime[j] = true;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    init();

    for (int i = 0; i < prime.size() - 1; i++) {
        int specialNum = prime[i] * prime[i + 1];
        if (specialNum > n) {
            cout << specialNum;
            break;
        }
    }

    return 0;
}