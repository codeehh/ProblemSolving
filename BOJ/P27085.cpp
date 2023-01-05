#include <iostream>
using namespace std;

long long arr[200001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    // 누적합
    for (int i = s - 1; i >= 1; i--) {
        arr[i] += arr[i + 1];
    }
    for (int i = s + 1; i <= n; i++) {
        arr[i] += arr[i - 1];
    }

    int p1 = s, p2 = s;  // 현재 위치
    int s1 = s, s2 = s;  // 저장된 위치
    int dir = -1;        // 방향
    bool first = true;   // 첫 턴인지
    long long ans = 0;   // 점수의 최대합
    while (true) {
        bool move = false;  // 이번 턴에 움직였는지
        if (dir == -1) {
            while (1 < p1) {
                if (arr[--p1] + arr[s2] < 0) {
                    p1++;
                    break;
                }
                move = true;
                if (arr[p1] + arr[s2] > ans) {
                    s1 = p1;
                    ans = arr[s1] + arr[s2];
                }
            }
        } else if (dir == 1) {
            while (p2 < n) {
                if (arr[s1] + arr[++p2] < 0) {
                    p2--;
                    break;
                }
                move = true;
                if (arr[s1] + arr[p2] > ans) {
                    s2 = p2;
                    ans = arr[s1] + arr[s2];
                }
            }
        }

        if (!move && !first)
            break;
        first = false;

        dir = -dir;
    }
    cout << ans;

    return 0;
}