#include <iostream>
#include <unordered_map>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unordered_map<int, int> umap1;
    unordered_map<int, int> umap2;
    for (int i = 0; i < 3; i++) {
        int a, b;
        cin >> a >> b;
        umap1[a]++;
        umap2[b]++;
    }
    for (auto x : umap1) {
        if (x.second % 2 == 1)
            cout << x.first << ' ';
    }
    for (auto y : umap2) {
        if (y.second % 2 == 1)
            cout << y.first << ' ';
    }

    return 0;
}