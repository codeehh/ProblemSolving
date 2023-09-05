#include <iostream>

using namespace std;

int solution(int n, int a, int b) {
    int answer = 1;

    while ((abs(b - a) > 1) || (min(a, b) % 2 != 1)) {
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        answer++;
    }

    return answer;
}