#include <string>
#include <vector>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;

    int lo = r1;
    int hi = r2;
    for (int i = 1; i <= r2; i++) {
        while (i * i + hi * hi > r2 * r2) {
            hi--;
        }
        if (i <= r1) {
            while (i * i + (lo - 1) * (lo - 1) >= r1 * r1) {
                lo--;
                if (i * i + lo * lo == r1 * r1)
                    break;
            }
        }
        answer += (i < r1 ? 2 * (hi - lo + 1) : 2 * hi + 1);
    }
    answer *= 2;
    answer += 2 * (r2 - r1 + 1);

    return answer;
}

// int main() {
//     solution(2, 3);
//     return 0;
// }