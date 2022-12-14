#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";

    for (int i = 1; i < food.size(); i++) {
        for (int j = 0; j < food[i] / 2; j++) {
            answer += (i + '0');
        }
    }
    answer += "0";
    string subs = answer.substr(0, answer.length() - 1);
    reverse(subs.begin(), subs.end());
    answer += subs;

    return answer;
}