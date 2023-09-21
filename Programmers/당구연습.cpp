#include <string>
#include <vector>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;

    for (int i = 0; i < balls.size(); i++) {
        int ballX = balls[i][0];
        int ballY = balls[i][1];

        int min_v = 987654321;
        if (!(startY == ballY && startX < ballX))
            min_v = min(min_v, (2 * m - ballX - startX) * (2 * m - ballX - startX) + (ballY - startY) * (ballY - startY));
        if (!(startY == ballY && ballX < startX))
            min_v = min(min_v, (-ballX - startX) * (-ballX - startX) + (ballY - startY) * (ballY - startY));
        if (!(startX == ballX && startY < ballY))
            min_v = min(min_v, (ballX - startX) * (ballX - startX) + (2 * n - ballY - startY) * (2 * n - ballY - startY));
        if (!(startX == ballX && ballY < startY))
            min_v = min(min_v, (ballX - startX) * (ballX - startX) + (-ballY - startY) * (-ballY - startY));

        answer.push_back(min_v);
    }

    return answer;
}