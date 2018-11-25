#include <algorithm>
#include <cmath>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int fun(long long x)
{
    long long l = 0, r = x;

    while (l < r) {
        long long mid = l + r >> 1;
        long long temp = (mid * mid - mid) / 2;
        if (temp < x)
            l = mid + 1;
        else
            r = mid;
    }
    return r;
}
int main()
{
    long long n, m;
    cin >> n >> m;
    long long ans1, ans2;
    ans1 = max(0ll, n - m * 2);
    if (m > 2)
        ans2 = n - fun(m);
    else {
        ans2 = n - m - 1;
    }
    if (m == 0) {
        ans1 = n;
        ans2 = n;
    }
    if (n == 1) {
        ans1 = 1;
        ans2 = 1;
    }
    if (ans2 < 0)
        ans2 = 0;
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}