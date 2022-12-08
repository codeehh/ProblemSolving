#include <iostream>
#include <vector>
using namespace std;

bool notPrime[119];
vector<int> prime;

void init() {
    notPrime[1] = true;
    for (int i = 2; i <= 118; i++) {
        if (!notPrime[i]) {
            prime.push_back(i);
            for (int j = i + i; j <= 118; j += i) {
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

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        int p1 = 0, p2 = prime.size() - 1;
        string ans = "No\n";
        while (p1 <= p2) {
            int sum = prime[p1] + prime[p2];
            if (sum == a) {
                ans = "Yes\n";
                break;
            } else if (sum < a) {
                p1++;
            } else {
                p2--;
            }
        }
        cout << ans;
    }

    return 0;
}