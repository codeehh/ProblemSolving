#include <string>
#include <vector>

using namespace std;

int answer = 25 * 50;
int fatigability_table[3][3] = {{1, 1, 1},
                                {5, 1, 1},
                                {25, 5, 1}};

void solve(int idx, int fatigability, vector<int> &picks, vector<string> &minerals) {
    if (fatigability >= answer) {
        return;
    }
    if (picks[0] == 0 && picks[1] == 0 && picks[2] == 0 || idx >= minerals.size()) {
        answer = min(answer, fatigability);
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (picks[i] > 0) {
            int fatigability_sum = 0;
            for (int j = 0; j < 5; j++) {
                if (idx + j < minerals.size()) {
                    char c = minerals[idx + j][0];
                    switch (c) {
                        case 'd':
                            fatigability_sum += fatigability_table[i][0];
                            break;
                        case 'i':
                            fatigability_sum += fatigability_table[i][1];
                            break;
                        case 's':
                            fatigability_sum += fatigability_table[i][2];
                            break;
                    }
                }
            }
            picks[i]--;
            solve(idx + 5, fatigability + fatigability_sum, picks, minerals);
            picks[i]++;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    solve(0, 0, picks, minerals);
    return answer;
}