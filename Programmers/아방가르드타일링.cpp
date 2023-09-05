#include <string>
#include <vector>

using namespace std;

const int M = 1000000007;

int basic[100001];
int dp[100001];
int dp2[100001];

void init(int n) {
    basic[1] = 1;
    basic[2] = 2;
    basic[3] = 5;
    for (int i = 4; i <= n; i++) {
        basic[i] = (i % 3 == 0 ? 4 : 2);
    }
    dp2[1] = 2;
    dp2[2] = 8;
    dp2[3] = 30;
}

int solution(int n) {
    int answer = 0;

    init(n);

    for (int i = 1; i <= n; i++) {
        dp[i] = basic[i];
        for (int j = 1; j <= 3; j++) {
            dp[i] = (dp[i] + (long long)dp[i - j] * basic[j]) % M;
        }
        if (i >= 5) {
            dp[i] = (dp[i] + dp2[i - 4]) % M;
            dp2[i - 1] = dp2[i - 4];
            for (int j = 0; j < 3; j++) {
                dp2[i - 1] = (dp2[i - 1] + (long long)dp[i - 1 - j] * basic[4 + j]) % M;
            }
        }
    }
    answer = dp[n];

    return answer;
}