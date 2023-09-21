#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool Comp(vector<string> a, vector<string> b) {
    return a[1] < b[1];
}

int time_diff(string time1, string time2) {
    return abs((stoi(time1.substr(0, 2)) * 60 + stoi(time1.substr(3, 2))) - (stoi(time2.substr(0, 2)) * 60 + stoi(time2.substr(3, 2))));
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;

    sort(plans.begin(), plans.end(), Comp);

    stack<vector<string>> plans_stack;
    vector<string> prev;
    for (int i = 0; i < plans.size(); i++) {
        vector<string> now = plans[i];
        if (i == plans.size() - 1) {
            answer.push_back(now[0]);
            break;
        }
        vector<string> next = plans[i + 1];
        int time = time_diff(now[1], next[1]);
        if (time == stoi(now[2])) {
            answer.push_back(now[0]);
        } else if (time < stoi(now[2])) {
            now[2] = to_string(stoi(now[2]) - time);
            plans_stack.push(now);
        } else if (time > stoi(now[2])) {
            answer.push_back(now[0]);
            time -= stoi(now[2]);
            while (!plans_stack.empty() && time > 0) {
                vector<string> recent = plans_stack.top();
                plans_stack.pop();
                if (time == stoi(recent[2])) {
                    answer.push_back(recent[0]);
                    time = 0;
                } else if (time < stoi(recent[2])) {
                    recent[2] = to_string(stoi(recent[2]) - time);
                    time = 0;
                    plans_stack.push(recent);
                } else if (time > stoi(recent[2])) {
                    answer.push_back(recent[0]);
                    time -= stoi(recent[2]);
                }
            }
        }
    }
    while (!plans_stack.empty()) {
        vector<string> recent = plans_stack.top();
        plans_stack.pop();
        answer.push_back(recent[0]);
    }

    return answer;
}