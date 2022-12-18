#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

pair<string, string> arr[100000];

struct Comp {
    bool operator()(pair<string, string> a, pair<string, string> b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + n, Comp());
    for (int i = 0; i < n; i++) {
        cout << arr[i].first << " " << arr[i].second << "\n";
    }

    return 0;
}