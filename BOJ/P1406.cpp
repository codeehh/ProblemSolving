#include <iostream>
#include <list>
using namespace std;

list<char> listt;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
        listt.push_back(str[i]);
    list<char>::iterator iter = listt.end();

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        char comm;
        cin >> comm;
        if (comm == 'L') {
            if (iter != listt.begin())
                iter--;
        } else if (comm == 'D') {
            if (iter != listt.end())
                iter++;
        } else if (comm == 'B') {
            if (iter != listt.begin()) {
                iter--;
                iter = listt.erase(iter);
            }
        } else if (comm == 'P') {
            char input;
            cin >> input;
            iter = listt.insert(iter, input);
            iter++;
        }
    }
    for (iter = listt.begin(); iter != listt.end(); iter++)
        cout << *iter;
    return 0;
}