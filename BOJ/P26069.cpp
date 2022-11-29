#include <iostream>
#include <unordered_set>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    unordered_set<string> dance;
    dance.insert("ChongChong");
    for (int i = 0; i < n; i++) {
        string person[2];
        cin >> person[0] >> person[1];
        for (int j = 0; j < 2; j++) {
            if (dance.find(person[j]) != dance.end()) {
                dance.insert(person[1 - j]);
            }
        }
    }
    cout << dance.size();
    return 0;
}