#include <iostream>
using namespace std;
int f[31];
int main()
{
    f[1] = 1;
    f[2] = 3;
    for (int i = 3; i <= 30; i++) {
        f[i] = f[i - 1] + f[i - 2] * 2;
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