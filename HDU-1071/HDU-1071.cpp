#include <cmath>
#include <iostream>
using namespace std;

struct P {
    double x, y;
};

int main()
{
    int n;
    cin >> n;
    while (n--) {
        P p[4];
        for (int i = 1; i <= 3; i++) {
            cin >> p[i].x >> p[i].y;
        }
        // y = kx + t
        double k = (p[3].y - p[2].y) / (p[3].x - p[2].x);
        double t = p[3].y - (k * p[3].x);

        // y = ax^2 + bx + c
        double a, b, c;
        a = (p[2].y - p[1].y) / (p[1].x - p[2].x) / (p[1].x - p[2].x);
        b = p[1].x * -2 * a;
        c = p[1].y + a * p[1].x * p[1].x;

        double ans = a / 3 * p[3].x * p[3].x * p[3].x + (b - k) / 2 * p[3].x * p[3].x + (c - t) * p[3].x;
        ans -= a / 3 * p[2].x * p[2].x * p[2].x + (b - k) / 2 * p[2].x * p[2].x + (c - t) * p[2].x;
        printf("%.2f\n", ans);
    }
    return 0;
}