#include <iostream>
using namespace std;
int f[305];
//f[i] 表示有i个石头时的方案
int main()
{
    int n;
    f[0] = f[1] = 1;
    for (int i = 3; i <= 303; i += 2) {
        for (int j = 303; j >= 0; j--) {
            f[j] += f[j - i];
        }
    }
    while (cin >> n) {
        cout << f[n] << endl;
    }
    return 0;
}