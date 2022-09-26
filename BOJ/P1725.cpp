#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int INF = 1000000001;
int arr[100000];

int n;

vector<int> segTree;

int makeSegTree(int node, int lo, int hi) {
    if (lo == hi) {
        return segTree[node] = lo;
    }
    int mid = (lo + hi) / 2;
    int leftIndex = makeSegTree(2 * node, lo, mid);
    int rightIndex = makeSegTree(2 * node + 1, mid + 1, hi);
    return segTree[node] = (arr[leftIndex] <= arr[rightIndex] ? leftIndex : rightIndex);
}

int findIdx(int node, int lo, int hi, int left, int right) {
    if (hi < left || right < lo)
        return INF;
    if (left <= lo && hi <= right)
        return segTree[node];
    int mid = (lo + hi) / 2;
    int leftIndex = findIdx(2 * node, lo, mid, left, right);
    int rightIndex = findIdx(2 * node + 1, mid + 1, hi, left, right);
    if (leftIndex == INF)
        return rightIndex;
    if (rightIndex == INF)
        return leftIndex;
    return arr[leftIndex] <= arr[rightIndex] ? leftIndex : rightIndex;
}

long long solve(int lo, int hi) {
    if (lo == hi) {
        return arr[lo];
    }
    int minIdx = findIdx(1, 0, n - 1, lo, hi);
    long long ret = (long long)arr[minIdx] * (hi - lo + 1);
    if (lo <= minIdx - 1)
        ret = max(ret, solve(lo, minIdx - 1));
    if (minIdx + 1 <= hi)
        ret = max(ret, solve(minIdx + 1, hi));
    return ret;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int h = (int)ceil(log2(n));
    int treeSize = (1 << (h + 1));
    segTree.clear();
    segTree.resize(treeSize);
    makeSegTree(1, 0, n - 1);
    cout << solve(0, n - 1) << '\n';

    return 0;
}