#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Info {
   public:
    string name;
    int score1;
    int score2;
    int score3;
};
bool comp(const Info& a, const Info& b) {
    if (a.score1 == b.score1 && a.score2 == b.score2 && a.score3 == b.score3)
        return a.name < b.name;
    if (a.score1 == b.score1 && a.score2 == b.score2)
        return a.score3 > b.score3;
    if (a.score1 == b.score1)
        return a.score2 < b.score2;
    return a.score1 > b.score1;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<Info> v;
    for (int i = 0; i < n; i++) {
        Info info;
        cin >> info.name >> info.score1 >> info.score2 >> info.score3;
        v.push_back(info);
    }
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < n; i++) {
        cout << v[i].name << "\n";
    }

    return 0;
}