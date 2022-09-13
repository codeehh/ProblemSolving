#include <iostream>
#include <vector>
using namespace std;

int n;
int scoreBoard[21][21];
int ans = 987654321;

vector<int> team1;
vector<int> team2;

void solve(int idx, int score1, int score2) {
    if (idx == n + 1) {
        ans = min(ans, abs(score1 - score2));
        return;
    }
    if (team1.size() != n / 2) {
        team1.push_back(idx);
        int sum = 0;
        for (int i = 0; i < team1.size(); i++) {
            sum += scoreBoard[idx][team1[i]];
            sum += scoreBoard[team1[i]][idx];
        }
        solve(idx + 1, score1 + sum, score2);
        team1.pop_back();
    }
    if (team2.size() != n / 2) {
        team2.push_back(idx);
        int sum = 0;
        for (int i = 0; i < team2.size(); i++) {
            sum += scoreBoard[idx][team2[i]];
            sum += scoreBoard[team2[i]][idx];
        }
        solve(idx + 1, score1, score2 + sum);
        team2.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> scoreBoard[i][j];
        }
    }
    solve(1, 0, 0);
    cout << ans;

    return 0;
}