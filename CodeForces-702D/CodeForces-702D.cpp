#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long d, k, a, b, t;
    cin >> d >> k >> a >> b >> t;
    long long ans = 0;
    if (k >= d) {
        ans = d * a;
    } else {
        ans += k * a;
        d -= k;
        long long circle = d / k;
        long long last = d % k;
        ans += min(circle * k * a + circle * t, circle * b * k);
        ans += min(last * a + t, last * b);
    }
    cout << ans << endl;
    return 0;
}