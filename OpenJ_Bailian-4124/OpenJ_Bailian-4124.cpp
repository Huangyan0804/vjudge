#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
#define scanff(n) scanf("%d", &n)
const int N = 20;
int f[1 << 16][N], w[N][N];
int main()
{
    int n;
    scanff(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanff(w[i][j]);
        }
    }
    /*

        状压DP
        f[i][j] = min(f[i][j], f[i-(1<<j)][k] + w[k][j]);
        min中第一个参数表示目前经过了i二进制中的点，最后停留在j点
        min中第二个参数表示目前未经过i进制中的j点，并且停留在了k点，和k点到j点的长度相加

    */
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;
    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {
                for (int k = 0; k < n; k++) {
                    if ((i - (1 << j)) >> k & 1) {
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);
                    }
                }
            }
        }
    }
    printf("%d\n", f[(1 << n) - 1][n - 1]);
    return 0;
}