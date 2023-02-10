#include <iostream>
using namespace std;

int n;

bool isPrime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(int depth, int num) {
    if (depth == n) {
        cout << num << "\n";
        return;
    }
    for (int i = 1; i <= 9; i += 2) {
        int nextNum = num * 10 + i;
        if (isPrime(nextNum)) {
            dfs(depth + 1, nextNum);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    dfs(1, 2);
    dfs(1, 3);
    dfs(1, 5);
    dfs(1, 7);

    return 0;
}