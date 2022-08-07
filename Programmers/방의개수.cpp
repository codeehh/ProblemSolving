#include <map>
#include <string>
#include <vector>

using namespace std;

const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

const pair<pair<int, int>, int> cross1[4] = {{{0, -1}, 7}, {{-1, 0}, 1}, {{0, 1}, 3}, {{1, 0}, 5}};
const pair<pair<int, int>, int> cross2[4] = {{{1, 0}, 3}, {{0, -1}, 5}, {{-1, 0}, 7}, {{0, 1}, 1}};

map<pair<int, int>, int> mapp;

int solution(vector<int> arrows) {
    int answer = 0;

    int y = 0;
    int x = 0;
    mapp[{y, x}] = 0;
    for (int i = 0; i < arrows.size(); i++) {
        int dir = arrows[i];
        int revDir = (arrows[i] + 4) % 8;
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if ((mapp[{y, x}] & (1 << revDir)) == 0) {
            if (mapp.find({ny, nx}) != mapp.end() && (mapp[{ny, nx}] & (1 << dir)) == 0) {
                answer++;
            }
            if (mapp.find({ny, nx}) == mapp.end() || (mapp.find({ny, nx}) != mapp.end() && (mapp[{ny, nx}] & (1 << dir)) == 0)) {
                for (int j = 0; j < 4; j++) {
                    if (dir == 2 * j + 1) {
                        if (mapp.find({ny + cross1[j].first.first, nx + cross1[j].first.second}) != mapp.end() && (mapp[{ny + cross1[j].first.first, nx + cross1[j].first.second}] & (1 << cross1[j].second)) != 0) {
                            answer++;
                        } else if (mapp.find({ny + cross2[j].first.first, nx + cross2[j].first.second}) != mapp.end() && (mapp[{ny + cross2[j].first.first, nx + cross2[j].first.second}] & (1 << cross2[j].second)) != 0) {
                            answer++;
                        }
                    }
                }
            }
        }
        mapp[{ny, nx}] = mapp[{ny, nx}] | (1 << dir);
        y = ny;
        x = nx;
    }

    return answer;
}