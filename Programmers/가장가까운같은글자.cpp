#include <string>
#include <vector>
#include <cstring>

using namespace std;

int record[26];

vector<int> solution(string s) {
    vector<int> answer;

    memset(record, -1, sizeof(record));
    for (int i = 0; i < s.length(); i++) {
        int idx = s[i] - 'a';
        if (record[idx] == -1)
            answer.push_back(-1);
        else
            answer.push_back(i - record[idx]);
        record[idx] = i;
    }

    return answer;
}