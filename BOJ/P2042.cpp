#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> segTree;
long long arr[1000000];

long long makeSegTree(int node, int lo, int hi) {
    if (lo == hi) {
        return segTree[node] = arr[lo];
    }
    int mid = (lo + hi) / 2;
    long long left = makeSegTree(node * 2, lo, mid);
    long long right = makeSegTree(node * 2 + 1, mid + 1, hi);
    return segTree[node] = (left + right);
}

void updateSegTree(int node, int lo, int hi, int idx, long long num) {
    if (idx < lo || hi < idx)
        return;
    if (lo <= idx && idx <= hi)
        segTree[node] += num;
    if (lo == hi)
        return;
    int mid = (lo + hi) / 2;
    updateSegTree(2 * node, lo, mid, idx, num);
    updateSegTree(2 * node + 1, mid + 1, hi, idx, num);
}

long long sumSegTree(int node, int lo, int hi, int left, int right) {
    if (hi < left || right < lo)
        return 0;
    if (left <= lo && hi <= right)
        return segTree[node];
    int mid = (lo + hi) / 2;
    long long leftSum = sumSegTree(2 * node, lo, mid, left, right);
    long long rightSum = sumSegTree(2 * node + 1, mid + 1, hi, left, right);
    return leftSum + rightSum;
}

void printSegTree(vector<long long> segTree) {
    int cnt = 1;
    while (cnt != segTree.size()) {
        for (int i = 0; i < cnt; i++) {
            cout << segTree[cnt + i] << ' ';
        }
        cout << '\n';
        cnt <<= 1;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int h = (int)ceil(log2(n));
    segTree.resize(1 << (h + 1));
    makeSegTree(1, 0, n - 1);
    for (int i = 0; i < m + k; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if (a == 1) {
            updateSegTree(1, 0, n - 1, b - 1, c - arr[b - 1]);
            arr[b - 1] = c;
        } else if (a == 2) {
            cout << sumSegTree(1, 0, n - 1, b - 1, c - 1) << "\n";
        }
    }
    return 0;
}