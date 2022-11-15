#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int game = 0; game < n; game++) {
        int m;
        cin >> m;
        long long kda[100][3];
        for (int mission = 0; mission < m; mission++) {
            int K, D, A;
            cin >> K >> D >> A;
            kda[mission][0] = K;
            kda[mission][1] = D;
            kda[mission][2] = A;
        }
        int k, d, a;
        cin >> k >> d >> a;
        long long ans = 0;
        for (int mission = 0; mission < m; mission++) {
            long long sum = 0;
            sum += k * kda[mission][0];
            sum -= d * kda[mission][1];
            sum += a * kda[mission][2];
            if (sum > 0)
                ans += sum;
        }
        cout << ans << "\n";
    }

    return 0;
}