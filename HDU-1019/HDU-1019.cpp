#include <algorithm>
#include <iostream>
using namespace std;
int gcd(long long n, long long m)
{
    return m ? gcd(m, n % m) : n;
}
int lcm(long long n, long long m)
{
    if (n < m)
        swap(n, m);
    return n * m / gcd(n, m);
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        long long n, a[10000];
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++) {
            a[i] = lcm(a[i - 1], a[i]);
        }
        cout << a[n - 1] << endl;
    }
    return 0;
}