#include <iostream>
using namespace std;

struct Trie {
    Trie* node[10];
    bool end;

    Trie() {
        for (int i = 0; i < 10; i++) {
            node[i] = NULL;
        }
        end = false;
    }

    bool regist(string str) {
        Trie* cur = this;
        for (int i = 0; i < str.length(); i++) {
            Trie*& next = cur->node[str[i] - '0'];
            // 마지막 노드인데 등록돼있다면 false
            if (i == str.length() - 1 && next != NULL) {
                return false;
            }
            if (next == NULL) {
                next = new Trie();
            }
            cur = next;
            // end로 등록된 노드를 지나친다면 false
            if (cur->end) {
                return false;
            }
        }
        cur->end = true;
        return true;
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        Trie trie;
        string ans = "YES";
        for (int j = 0; j < n; j++) {
            string phone;
            cin >> phone;
            if (ans == "YES" && !trie.regist(phone)) {
                ans = "NO";
            }
        }
        cout << ans << '\n';
    }

    return 0;
}