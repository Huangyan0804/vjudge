#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        double x = n * log10(n );
        double t = x - floor(x);
        double ans = pow(10, t);
        printf("%d\n", int(ans));
    }
    return 0;
}