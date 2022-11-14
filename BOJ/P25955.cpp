#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    string arr[1000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unordered_map<string, int> hashMap;
    hashMap.insert({"B", 5});
    hashMap.insert({"S", 4});
    hashMap.insert({"G", 3});
    hashMap.insert({"P", 2});
    hashMap.insert({"D", 1});

    int idx1 = -1, idx2 = -1;
    for (int i = 0; i < n - 1; i++) {
        string tier1 = arr[i].substr(0, 1);
        string tier2 = arr[i + 1].substr(0, 1);
        int num1 = stoi(arr[i].substr(1));
        int num2 = stoi(arr[i + 1].substr(1));
        if (hashMap[tier1] < hashMap[tier2] || (hashMap[tier1] == hashMap[tier2] && num1 < num2)) {
            idx1 == -1 ? idx1 = i : idx2 = i + 1;
            if (idx2 != -1)
                break;
        }
    }
    if (idx1 == -1)
        cout << "OK";
    else if (idx2 == -1)
        cout << "KO\n"
             << arr[idx1 + 1] << " " << arr[idx1];
    else
        cout << "KO\n"
             << arr[idx2] << " " << arr[idx1];
    return 0;
}