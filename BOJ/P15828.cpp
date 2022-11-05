#include <iostream>
#include <queue>
using namespace std;

queue<int> buffer;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr[100000];
    while (true) {
        int input;
        cin >> input;
        if (input == -1) {
            break;
        }
        if (input == 0) {
            buffer.pop();
        } else {
            if (buffer.size() < n) {
                buffer.push(input);
            }
        }
    }
    if (buffer.empty()) {
        cout << "empty";
    } else {
        while (!buffer.empty()) {
            cout << buffer.front() << " ";
            buffer.pop();
        }
    }
    return 0;
}