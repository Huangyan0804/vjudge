#include <iostream>
using namespace std;
int main()
{
    unsigned long long a, b, p;
    cin >> a >> b >> p;
    unsigned long long ans = 0;
    while (b) {
        if (b & 1)
            ans = ans + a % p;
        a = a * 1ll * 2 % p;
        b >>= 1;
    }
    cout << ans % p << endl;
    return 0;
}