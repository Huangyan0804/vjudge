#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
struct S {
    int j, f;
};
bool cmp(S a, S b)
{
    if (a.f != b.f)
        return (double)a.j / a.f > (double)b.j / b.f;
    else
        return a.j > b.j;
}
int main()
{
    int n, m;
    while (cin >> m >> n && (n != -1 || m != -1)) {
        S num[1001];
        for (int i = 0; i < n; i++) {
            cin >> num[i].j >> num[i].f;
        }
        sort(num, num + n, cmp);
        double ans = 0;
        for (int i = 0; i < n && m > 0; i++) {
            if (m >= num[i].f) {
                ans += num[i].j;
                m -= num[i].f;
            } else {
                ans += ((double)m / num[i].f) * num[i].j;
                m -= num[i].f;
            }
        }
        printf("%.3f\n", ans);
    }
    return 0;
}