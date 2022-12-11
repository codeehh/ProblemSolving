#include <string>
#include <vector>

using namespace std;

int divisorCnt[100001];

void init(int number) {
    for (int i = 1; i <= number; i++) {
        for (int j = 1; i * j <= number; j++) {
            divisorCnt[i * j]++;
        }
    }
}

int solution(int number, int limit, int power) {
    int answer = 0;

    init(number);

    for (int i = 1; i <= number; i++) {
        if (divisorCnt[i] > limit)
            answer += power;
        else
            answer += divisorCnt[i];
    }

    return answer;
}