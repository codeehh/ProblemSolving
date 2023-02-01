#include <iostream>
using namespace std;

char board[100][100];
bool horizonVisited[100][100];
bool verticalVisited[100][100];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    int horizon = 0;
    int vertical = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '.' && (!horizonVisited[i][j] || !verticalVisited[i][j])) {
                // 가로 검사
                if (!horizonVisited[i][j]) {
                    int cnt = 1;
                    while (j + cnt < n && board[i][j + cnt] == '.') {
                        horizonVisited[i][j + cnt] = true;
                        cnt++;
                    }
                    if (cnt >= 2)
                        horizon++;
                }
                // 세로 검사
                if (!verticalVisited[i][j]) {
                    int cnt = 1;
                    while (i + cnt < n && board[i + cnt][j] == '.') {
                        verticalVisited[i + cnt][j] = true;
                        cnt++;
                    }
                    if (cnt >= 2)
                        vertical++;
                }
                horizonVisited[i][j] = true;
                verticalVisited[i][j] = true;
            }
        }
    }
    cout << horizon << " " << vertical;

    return 0;
}