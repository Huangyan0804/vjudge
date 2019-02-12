#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int f[10005], a[10005];
int main()
{
    int n;
    while (cin >> n && n) {
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        f[0] = a[0];
        int sum = a[0], l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            f[i] = max(f[i - 1] + a[i], a[i]);
            if (f[i] > sum) {
                sum = f[i];
                r = i;
            }
        }
        if (sum >= 0) {
            int temp = 0;
            for (int i = r; i >= 0; i--) {
                temp += a[i];
                if (temp == sum)
                    l = i;
            }
        } else {
            sum = 0;
            l = 0, r = n - 1;
        }
        printf("%d %d %d\n", sum, a[l], a[r]);
    }
    return 0;
}