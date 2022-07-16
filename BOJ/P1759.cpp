#include <iostream>
#include <algorithm>
using namespace std;
char arr[15];
char sel[15];
int n, r;
void comb(int idx, int sidx) {
    if (sidx == r) {
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < r; i++) {
            if (sel[i] == 'a' || sel[i] == 'e' || sel[i] == 'i' || sel[i] == 'o' || sel[i] == 'u')
                cnt1++;
            else
                cnt2++;
        }
        if (cnt1 < 1 || cnt2 < 2)
            return;
        for (int i = 0; i < r; i++) {
            printf("%c", sel[i]);
        }
        printf("\n");
        return;
    }
    for (int i = idx; i <= n - r + sidx; i++) {
        sel[sidx] = arr[i];
        comb(i + 1, sidx + 1);
    }
}

int main(void) {
    scanf("%d %d", &r, &n);
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%c", &arr[i]);
    }
    sort(arr, arr + n);
    comb(0, 0);
    return 0;
}