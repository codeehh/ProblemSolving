#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;

    vector<double> pSum;
    pSum.push_back(0);
    while (k != 1) {
        int temp = k;
        if (k % 2 == 0)
            k /= 2;
        else
            k = k * 3 + 1;
        pSum.push_back(pSum[pSum.size() - 1] + ((double)temp + k) / 2);
    }

    for (int i = 0; i < ranges.size(); i++) {
        int a = ranges[i][0];
        int b = ranges[i][1];
        answer.push_back((a - b >= pSum.size() ? -1 : pSum[pSum.size() - 1 + b] - pSum[a]));
    }

    return answer;
}