#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int divisorCnt[5000001];

void init(int e) {
    for (int i = 1; i <= e; i++) {
        for (int j = 1; i * j <= e; j++) {
            divisorCnt[i * j]++;
        }
    }
}

pair<int, int> cnt[5000001];
vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;

    init(e);

    cnt[e].first = divisorCnt[e];
    cnt[e].second = e;

    for (int i = e - 1; i >= 1; i--) {
        if (divisorCnt[i] >= cnt[i + 1].first) {
            cnt[i].first = divisorCnt[i];
            cnt[i].second = i;
        } else {
            cnt[i].first = cnt[i + 1].first;
            cnt[i].second = cnt[i + 1].second;
        }
    }

    for (int i = 0; i < starts.size(); i++) {
        answer.push_back(cnt[starts[i]].second);
    }

    return answer;
}

int main(void) {
    vector<int> starts;
    for (int i = 0; i < 100000; i++) {
        starts.push_back(1);
    }
    vector<int> results = solution(5000000, starts);
    for (int num : results) {
        cout << num << "\n";
    }
    return 0;
}