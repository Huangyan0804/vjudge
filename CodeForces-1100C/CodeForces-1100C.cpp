#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    const double pi = 3.14159265359;
    int n;
    double r;
    cin >> n >> r;
    double ans = 0;
    double jd = double(180) * (n - 2) / n / 2;
    double hd = jd * pi / 180;
    ans = (cos(hd) * r) / (double(1) - cos(hd));
    printf("%.7f", ans);
    return 0;
}