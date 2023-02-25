#include <iostream>
using namespace std;

int sudoku[9][9];

pair<int, int> nextRC(pair<int, int> rc) {
    int r = rc.first;
    int c = rc.second;
    while (true) {
        if ((r == 9 && c == 0) || sudoku[r][c] == 0) {
            break;
        }
        if (c == 8) {
            r++;
            c = 0;
        } else {
            c++;
        }
    }
    return {r, c};
}

bool columnCheck(int c, int num) {
    for (int r = 0; r < 9; r++) {
        if (sudoku[r][c] == num) {
            return false;
        }
    }
    return true;
}
bool rowCheck(int r, int num) {
    for (int c = 0; c < 9; c++) {
        if (sudoku[r][c] == num) {
            return false;
        }
    }
    return true;
}
bool boxCheck(int boxR, int boxC, int num) {
    for (int r = boxR; r < boxR + 3; r++) {
        for (int c = boxC; c < boxC + 3; c++) {
            if (sudoku[r][c] == num) {
                return false;
            }
        }
    }
    return true;
}

bool finish = false;
void dfs(pair<int, int> rc) {
    int r = rc.first;
    int c = rc.second;
    if (r == 9 && c == 0) {
        finish = true;
        return;
    }
    for (int num = 1; num <= 9; num++) {
        if (columnCheck(c, num) && rowCheck(r, num) && boxCheck((r / 3) * 3, (c / 3) * 3, num)) {
            sudoku[r][c] = num;
            dfs(nextRC(rc));
            if (finish) {
                return;
            }
        }
    }
    sudoku[r][c] = 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
        }
    }
    dfs(nextRC({0, 0}));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}