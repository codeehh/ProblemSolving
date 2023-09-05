#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    priority_queue<int> pq;
    for (int i = 0; i < works.size(); i++) {
        pq.push(works[i]);
    }
    while (n--) {
        int top_work = pq.top();
        pq.pop();
        if (top_work == 0)
            break;
        pq.push(top_work - 1);
    }
    while (!pq.empty()) {
        int top_work = pq.top();
        pq.pop();
        if (top_work == 0)
            break;
        answer += ((long long)top_work * top_work);
    }

    return answer;
}