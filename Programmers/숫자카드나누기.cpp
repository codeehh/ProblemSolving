#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solve(vector<int> a, vector<int> b) {
    unordered_set<int> uset;
    for (int i = 1; i * i <= a[0]; i++) {
        if (a[0] % i == 0) {
            uset.insert(i);
            uset.insert(a[0] / i);
        }
    }

    for (int i = 1; i < a.size(); i++) {
        vector<int> erasee;
        for (int num : uset) {
            if (a[i] % num != 0) {
                erasee.push_back(num);
            }
        }
        for (int j = 0; j < erasee.size(); j++) {
            uset.erase(erasee[j]);
        }
    }
    for (int i = 0; i < b.size(); i++) {
        vector<int> erasee;
        for (int num : uset) {
            if (b[i] % num == 0) {
                erasee.push_back(num);
            }
        }
        for (int j = 0; j < erasee.size(); j++) {
            uset.erase(erasee[j]);
        }
    }
    if (uset.size() == 0)
        return 0;
    return *max_element(uset.begin(), uset.end());
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;

    answer = max(solve(arrayA, arrayB), solve(arrayB, arrayA));

    return answer;
}