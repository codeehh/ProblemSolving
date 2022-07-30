#include <iostream>
using namespace std;

int dist[99999];
int cost[100000];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
        cin >> dist[i];
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    long long ans = 0;
    int cheapCost = cost[0];
    for (int i = 0; i < n - 1; i++) {
        cheapCost = min(cheapCost, cost[i]);
        ans += (long long)dist[i] * cheapCost;
    }
    cout << ans;
    return 0;
}