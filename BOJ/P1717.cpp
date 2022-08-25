#include <iostream>
using namespace std;

int link[1000001];

struct UnionFind {
    UnionFind(int n) {
        for (int i = 0; i <= n; i++) {
            link[i] = i;
        }
    }

    int find(int a) {
        if (a == link[a])
            return a;
        return link[a] = find(link[a]);
    }
    void unite(int a, int b) {
        if (find(a) != find(b)) {
            link[find(a)] = find(b);
        }
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    UnionFind uf = UnionFind(n);

    for (int i = 0; i < m; i++) {
        int comm, a, b;
        cin >> comm >> a >> b;
        if (comm == 0) {
            uf.unite(a, b);
        } else if (comm == 1) {
            if (uf.find(a) == uf.find(b)) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }

    return 0;
}