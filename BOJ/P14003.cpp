#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1000000][2];
int len[1000001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    fill_n(len, n + 1, -1000000001);
    int max_len = 0;
    int max_idx = -1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0];
        auto iter = lower_bound(len, len + max_len, arr[i][0]);
        int idx = iter - len;
        if (*iter > arr[i][0]) {
            len[idx] = arr[i][0];
            arr[i][1] = idx;
        } else if (*iter < arr[i][0]) {
            len[idx + 1] = arr[i][0];
            arr[i][1] = idx + 1;
            max_len = idx + 1;
            max_idx = i;
        }
    }
    cout << max_len << "\n";
    vector<int> lis;
    int val = 1000000001;
    for (int i = max_idx; i >= 0; i--) {
        if (arr[i][1] == max_len && arr[i][0] < val) {
            max_len--;
            val = arr[i][0];
            lis.push_back(arr[i][0]);
        }
        if (max_len == 0)
            break;
    }
    for (int i = lis.size() - 1; i >= 0; i--) {
        cout << lis[i] << " ";
    }

    return 0;
}