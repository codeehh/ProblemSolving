#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;

    unordered_map<string, int> name_to_order;
    for (int i = 0; i < players.size(); i++) {
        name_to_order[players[i]] = i;
    }
    for (int i = 0; i < callings.size(); i++) {
        int order = name_to_order[callings[i]];
        name_to_order[players[order]]--;
        name_to_order[players[order - 1]]++;
        swap(players[order], players[order - 1]);
    }
    answer = players;

    return answer;
}