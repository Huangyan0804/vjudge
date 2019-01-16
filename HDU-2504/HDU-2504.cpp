#include <iostream>
using namespace std;
int gcd(int n, int m)
{
    return m == 0 ? n : gcd(m, n % m);
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        for (int i = 2;; i++) {
            int temp = b * i;
            if (gcd(a, temp) == b) {
                cout << temp << endl;
                break;
            }
        }
    }
    return 0;
}