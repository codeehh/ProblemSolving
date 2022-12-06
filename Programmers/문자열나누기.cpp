#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    int cnt1 = 0, cnt2 = 0;
    char c;
    for (int i = 0; i < s.length(); i++) {
        if (cnt1 == 0) {
            cnt1 = 1;
            c = s[i];
            continue;
        }

        if (s[i] == c)
            cnt1++;
        else
            cnt2++;

        if (cnt1 == cnt2) {
            answer++;
            cnt1 = 0;
            cnt2 = 0;
        }
    }
    if (cnt1 != cnt2)
        answer++;
    return answer;
}