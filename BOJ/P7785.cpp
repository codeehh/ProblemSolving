#include <iostream>
#include <set>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    set<string, greater<>> record;
    for (int i = 0; i < n; i++) {
        string name, action;
        cin >> name >> action;

        if (action == "enter")
            record.insert(name);
        else if (action == "leave")
            record.erase(name);
    }
    for (string name : record) {
        cout << name << "\n";
    }

    return 0;
}