#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;

    priority_queue<int> pq;
    for (int i = 0; i < enemy.size(); i++) {
        n -= enemy[i];
        pq.push(enemy[i]);
        while (n < 0 && k > 0) {
            n += pq.top();
            pq.pop();
            k--;
        }
        if (n < 0) {
            answer = i;
            break;
        }
    }
    if (n >= 0)
        answer = enemy.size();

    return answer;
}