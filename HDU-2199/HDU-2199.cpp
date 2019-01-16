#include <cmath>
#include <iostream>
using namespace std;
double check(double x)
{
    double ans = 0;
    ans = 8 * x * x * x * x + 7 * x * x * x + 2 * x * x + 3 * x + 6;
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        double y;
        cin >> y;
        double l = -1, r = 101;
        while (r - l >= 1e-6) {
            double mid = (l + r) / 2;
            if (check(mid) - y > 1e-6)
                r = mid;
            else
                l = mid;
        }
        if (r < 0 || r > 100)
            printf("No solution!\n");
        else
            printf("%.4f\n", r);
    }
    return 0;
}