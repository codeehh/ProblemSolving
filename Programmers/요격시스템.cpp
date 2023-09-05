#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Comp(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;

    sort(targets.begin(), targets.end(), Comp);

    int x = -1;
    for (int i = 0; i < targets.size(); i++) {
        if (x < targets[i][0]) {
            answer++;
            x = targets[i][1] - 1;
        }
    }

    return answer;
}