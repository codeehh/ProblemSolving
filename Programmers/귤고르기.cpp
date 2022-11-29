#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    unordered_map<int, int> sizeToCnt;
    for (int i = 0; i < tangerine.size(); i++) {
        sizeToCnt[tangerine[i]]++;
    }
    priority_queue<int> pq;
    for (auto cnt : sizeToCnt) {
        pq.push(cnt.second);
    }
    while (!pq.empty() && k > 0) {
        k -= pq.top();
        pq.pop();
        answer++;
    }

    return answer;
}