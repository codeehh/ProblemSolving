#include <iostream>
#include <set>
using namespace std;

set<string> sett;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, a, b;
    cin >> s >> a >> b;

    int pidx = 0;
    while ((pidx = s.find(a, pidx)) != -1) {
        int sidx = pidx + (a.length() > b.length() ? a.length() - b.length() : 0);
        while ((sidx = s.find(b, sidx)) != -1) {
            sett.insert(s.substr(pidx, sidx - pidx + b.length()));
            sidx++;
        }
        pidx++;
    }
    cout << sett.size();

    return 0;
}