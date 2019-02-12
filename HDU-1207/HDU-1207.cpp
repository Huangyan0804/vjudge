#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
unsigned long long f[80], d[80];
int main()
{
    d[1] = 1;
    for (int i = 2; i <= 64; i++) {
        d[i] = d[i - 1] * 2 + 1;
    }
    memset(f, 0x3f, sizeof(f));
    f[1] = 1;
    for (int i = 2; i <= 64; i++) {
        for (int j = 0; j < i; j++) {
            f[i] = min(f[i], f[j] * 2 + d[i - j]);
        }
    }
    int n;
    while (cin >> n) {
        cout << f[n] << endl;
    }
    return 0;
}