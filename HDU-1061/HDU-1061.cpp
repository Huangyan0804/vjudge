#include <algorithm>
#include <iostream>
using namespace std;
int qmi(long long a, long long b, int c)
{
    long long t = a, res = 1;
    while (b) {
        if (b & 1)
            res = res * t % c;
        b >>= 1;
        t = t * t % c;
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        long long a;
        cin >> a;
        cout << qmi(a, a, 10) << endl;
    }
    return 0;
}