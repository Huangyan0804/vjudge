#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
struct P {
    double l, r;
    bool flag;
} a[1005];
bool cmp(P a, P b)
{
    return a.l < b.l;
}
int main()
{
    int n, d;
    int t = 1;
    while (cin >> n >> d && (n || d)) {
        bool flag = true;
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            if (y > d) {
                flag = false;
            }
            double temp = sqrt(d * d - y * y);
            a[i].l = x - temp, a[i].r = x + temp;
            a[i].flag = false;
        }
        sort(a, a + n, cmp);
        double pos = -100000000, ans = 0;
        for (int i = 0; i < n; i++) {
            if (!a[i].flag) {
                ans++;
                pos = a[i].r;
                a[i].flag = true;
                for (int j = i + 1; j < n; j++) {
                    if (a[j].l <= pos) {
                        a[j].flag = true;
                    } else
                        break;
                }
            }
        }
        if (!flag) {
            ans = -1;
        }
        printf("Case %d: ", t++);
        cout << ans << endl;
    }

    return 0;
}