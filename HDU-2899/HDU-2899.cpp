#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
double f(double x, double y)
{
    double ans;
    ans = 6 * x * x * x * x * x * x * x + 8 * x * x * x * x * x * x
        + 7 * x * x * x + 5 * x * x - y * x;
    return ans;
}
double f0(double x, double y)
{
    double ans;
    ans = 42 * x * x * x * x * x * x + 48 * x * x * x * x * x
        + 21 * x * x + 10 * x - y;
    return ans;
}
double binary(double y)
{
    double l = 0, r = 100;
    while (r - l > 1e-7) {
        double mid = (l + r) / 2;
        if (f0(mid, y) > 0)
            r = mid;
        else
            l = mid;
    }
    return f(r, y);
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        double y;
        cin >> y;
        double ans = binary(y);
        printf("%.4f\n", ans);
    }
    return 0;
}