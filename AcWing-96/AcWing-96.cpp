#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int f[20], d[20];
int main()
{
    d[1] = 1;
    for (int i = 2; i <= 12; i++) {
        d[i] = d[i - 1] * 2 + 1;
    }
    memset(f, 0x3f, sizeof(f));
    f[1] = 1;
    for (int i = 2; i <= 12; i++) {
        for (int j = 0; j < i; j++) {
            f[i] = min(f[i], f[j] * 2 + d[i - j]);
        }
    }
    for (int i = 1; i <= 12; i++) {
        cout << f[i] << endl;
    }
    return 0;
}