#include <cstring>
#include <iostream>
using namespace std;
int f[30];
int main()
{
    f[0] = 1;
    f[1] = 3;
    f[2] = 7;
    for (int i = 3; i <= 20; i++) {
        f[i] = f[i - 1] * 2 + f[i - 2];
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << f[n] << endl;
    }
    return 0;
}