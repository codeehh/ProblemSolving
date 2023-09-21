#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    answer.push_back(-1);
    answer.push_back(-1);

    int len = 1000001;
    int p1 = 0, p2 = 0;
    int sum = sequence[0];
    int s_size = sequence.size();
    sequence.push_back(0);
    while (p1 < s_size && p2 < s_size) {
        if (sum == k) {
            if (p2 - p1 + 1 < len) {
                answer[0] = p1;
                answer[1] = p2;
                len = p2 - p1 + 1;
            }
            sum += sequence[++p2];
        } else if (sum < k) {
            sum += sequence[++p2];
        } else {
            sum -= sequence[p1++];
        }
    }

    return answer;
}