#include <cstring>
#include <iostream>
using namespace std;
const int N = 1 << 20, M = 20;
int f[N][M], w[M][M];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }
    memset(f, 0x3f, sizeof(f));
    f[1][0] = 0;
    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {
                for (int k = 0; k < n; k++) {
                    if ((i - (1 << j)) >> k & 1)
                        f[i][j] = min(f[i - (1 << j)][k] + w[k][j], f[i][j]);
                }
            }
        }
    }
    cout << f[(1 << n) - 1][n - 1] << endl;
    return 0;
}