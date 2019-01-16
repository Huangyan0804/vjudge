#include <algorithm>
#include <iostream>
using namespace std;
int qmi(int a, int b, int c)
{
    int t = a, res = 1;
    while (b) {
        if (b & 1)
            res = res * 1ll * t % c;
        b >>= 1;
        t = t * 1ll * t % c;
    }
    return res % c;
}
bool is_prime(int n)
{
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int main()
{
    int a, b;
    while (cin >> a >> b && (a || b)) {
        if (is_prime(a)) {
            cout << "no" << endl;
        } else if (qmi(b, a, a) == b) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}