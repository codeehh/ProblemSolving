#include <iostream>
#include <list>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        list<char> cList;
        list<char>::iterator iter = cList.begin();
        string str;
        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            char c = str[i];
            if (c == '-') {
                if (iter != cList.begin()) {
                    iter--;
                    iter = cList.erase(iter);
                }
            } else if (c == '<') {
                if (iter != cList.begin()) {
                    iter--;
                }
            } else if (c == '>') {
                if (iter != cList.end()) {
                    iter++;
                }
            } else {
                cList.insert(iter, c);
            }
        }
        iter = cList.begin();
        while (iter != cList.end()) {
            cout << *(iter++);
        }
        cout << "\n";
    }

    return 0;
}