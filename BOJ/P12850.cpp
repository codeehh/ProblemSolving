#include <iostream>
#include <vector>
using namespace std;

const int M = 1000000007;

vector<vector<int>> adj = {{0, 1, 1, 0, 0, 0, 0, 0},
                           {1, 0, 1, 1, 0, 0, 0, 0},
                           {1, 1, 0, 1, 1, 0, 0, 0},
                           {0, 1, 1, 0, 1, 1, 0, 0},
                           {0, 0, 1, 1, 0, 1, 0, 1},
                           {0, 0, 0, 1, 1, 0, 1, 0},
                           {0, 0, 0, 0, 0, 1, 0, 1},
                           {0, 0, 0, 0, 1, 0, 1, 0}};

vector<vector<int>> temp = {{0, 1, 1, 0, 0, 0, 0, 0},
                            {1, 0, 1, 1, 0, 0, 0, 0},
                            {1, 1, 0, 1, 1, 0, 0, 0},
                            {0, 1, 1, 0, 1, 1, 0, 0},
                            {0, 0, 1, 1, 0, 1, 0, 1},
                            {0, 0, 0, 1, 1, 0, 1, 0},
                            {0, 0, 0, 0, 0, 1, 0, 1},
                            {0, 0, 0, 0, 1, 0, 1, 0}};

void mul_mat(vector<vector<int>> a, vector<vector<int>> b) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int summ = 0;
            for (int k = 0; k < 8; k++) {
                summ = (summ + ((long long)a[i][k] * b[k][j] % M)) % M;
            }
            temp[i][j] = summ;
        }
    }
}

void dq(int d) {
    if (d == 1) {
        return;
    }
    if (d % 2 == 0) {
        dq(d / 2);
        mul_mat(temp, temp);
    } else {
        dq(d / 2);
        mul_mat(temp, temp);
        mul_mat(adj, temp);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int d;
    cin >> d;

    dq(d);
    cout << temp[0][0];

    return 0;
}