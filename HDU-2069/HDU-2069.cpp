#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int f[101][251];
int main()
{
    int n, w[6] = { 1, 5, 10, 25, 50 };
    while (cin >> n) {
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 0; i < 5; i++) {
            for (int j = 1; j <= 100; j++) { //硬币个数
                for (int k = w[i]; k <= 250; k++) {
                    // f[j][k] 表示用j个硬币表示k元的方案数
                    f[j][k] += f[j - 1][k - w[i]];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= 100; i++)
            ans += f[i][n]; // 答案为1-100个硬币表示n元钱的总方案数
        cout << ans << endl;
    }
    return 0;
}