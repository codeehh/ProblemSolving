#include <iostream>
using namespace std;

int P[1001];
int knapsack[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            knapsack[j] = max(knapsack[j], knapsack[j - i] + P[i]);
        }
    }
    cout << knapsack[n];

    return 0;
}