#include <string>
#include <vector>

using namespace std;

long long dp[2];

long long solution(vector<int> sequence) {
    long long max_v = sequence[0];
    long long min_v = sequence[0];

    dp[0] = sequence[0];
    dp[1] = sequence[0];
    int flag = -1;
    for (int i = 1; i < sequence.size(); i++) {
        sequence[i] *= flag;
        flag *= -1;

        if (dp[0] <= 0)
            dp[0] = sequence[i];
        else
            dp[0] += sequence[i];

        if (dp[1] >= 0)
            dp[1] = sequence[i];
        else
            dp[1] += sequence[i];

        max_v = max(max_v, dp[0]);
        min_v = min(min_v, dp[1]);
    }

    return max(max_v, -min_v);
}