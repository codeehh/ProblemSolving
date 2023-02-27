#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pair<queue<int>, queue<int>> tree[1 << 11];
    int h, k, r;
    cin >> h >> k >> r;
    for (int i = (1 << h); i < (1 << (h + 1)); i++) {
        for (int j = 0; j < k; j++) {
            int task;
            cin >> task;
            tree[i].first.push(task);
        }
    }
    int day = 0;
    int sum = 0;
    while (day != r) {
        day++;
        // 루트 노드
        // 홀수날
        if (day % 2 == 1) {
            if (!tree[1].first.empty()) {
                sum += tree[1].first.front();
                tree[1].first.pop();
            }
        }
        // 짝수날
        else {
            if (!tree[1].second.empty()) {
                sum += tree[1].second.front();
                tree[1].second.pop();
            }
        }

        // 중간노드
        for (int i = 2; i < (1 << h); i++) {
            // 홀수날
            if (day % 2 == 1) {
                if (!tree[i].first.empty()) {
                    // 부모의 왼쪽 노드면
                    if (i % 2 == 0) {
                        tree[i / 2].first.push(tree[i].first.front());
                        tree[i].first.pop();
                    }
                    // 부모의 오른쪽 노드면
                    else {
                        tree[i / 2].second.push(tree[i].first.front());
                        tree[i].first.pop();
                    }
                }
            }
            // 짝수날
            else {
                if (!tree[i].second.empty()) {
                    // 부모의 왼쪽 노드면
                    if (i % 2 == 0) {
                        tree[i / 2].first.push(tree[i].second.front());
                        tree[i].second.pop();
                    }
                    // 부모의 오른쪽 노드면
                    else {
                        tree[i / 2].second.push(tree[i].second.front());
                        tree[i].second.pop();
                    }
                }
            }
        }

        // 말단노드
        for (int i = (1 << h); i < (1 << (h + 1)); i++) {
            if (!tree[i].first.empty()) {
                // 부모의 왼쪽 노드면
                if (i % 2 == 0) {
                    tree[i / 2].first.push(tree[i].first.front());
                    tree[i].first.pop();
                }
                // 부모의 오른쪽 노드면
                else {
                    tree[i / 2].second.push(tree[i].first.front());
                    tree[i].first.pop();
                }
            }
        }
    }
    cout << sum;

    return 0;
}