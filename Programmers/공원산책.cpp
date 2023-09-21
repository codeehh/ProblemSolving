#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int H, W;

bool OutCheck(int y, int x) {
    return 0 <= y && y < H && 0 <= x && x < W;
}
bool ObstructionCheck(int y, int x, vector<string> &park) {
    return park[y][x] != 'X';
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    answer.push_back(-1);
    answer.push_back(-1);

    H = park.size();
    W = park[0].length();

    int y = -1;
    int x = -1;
    for (int i = 0; i < park.size(); i++) {
        bool find_s = false;
        for (int j = 0; j < park[i].length(); j++) {
            if (park[i][j] == 'S') {
                find_s = true;
                y = i;
                x = j;
                break;
            }
        }
        if (find_s)
            break;
    }

    unordered_map<char, pair<int, int>> dir_to_yx;
    dir_to_yx['N'] = {-1, 0};
    dir_to_yx['S'] = {1, 0};
    dir_to_yx['W'] = {0, -1};
    dir_to_yx['E'] = {0, 1};
    for (int i = 0; i < routes.size(); i++) {
        char dir = routes[i][0];
        int len = routes[i][2] - '0';

        pair<int, int> yx = dir_to_yx[dir];

        int ty = y;
        int tx = x;
        bool pass = true;
        for (int j = 0; j < len; j++) {
            ty += yx.first;
            tx += yx.second;
            if (!(OutCheck(ty, tx) && ObstructionCheck(ty, tx, park))) {
                pass = false;
                break;
            }
        }
        if (pass) {
            y = ty;
            x = tx;
        }
    }
    answer[0] = y;
    answer[1] = x;

    return answer;
}