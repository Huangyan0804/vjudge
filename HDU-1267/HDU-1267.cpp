#include <cstring>
#include <iostream>
using namespace std;
int m, n;
long long f[22][22];
int main()
{
    //memset(f, 0, sizeof(f));
    for (int i = 1; i <= 20; i++) {
        f[i][1] = i;
    }
    f[1][1] = 1;
    for (int i = 2; i <= 20; i++) {
        for (int j = 2; j <= i; j++) {
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    while (cin >> m >> n) {
        cout << f[m][n] << endl;
    }
    return 0;
}