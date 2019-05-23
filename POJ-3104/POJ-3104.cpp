#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
ll a[N];
int n, k;
bool check(ll x)
{
    ll sum = 0;
    // k*x1 + (mid-x1) >= a[i]
    // k*x1 - x1 = a[i] - mid
    // x1*(k-1) = a[i] - mid
    // x1 = (a[i]-mid) / k-1;
    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            sum += (a[i] - x + k - 2) / (k - 1); // 向上取整
        }
    }
    if (sum > x)
        return false;
    else
        return true;
}
int main()
{

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    scanf("%d", &k);
    if (k == 1) {
        printf("%lld\n", *max_element(a, a + n));
    } else {
        ll l = *min_element(a, a + n) / k, r = *max_element(a, a + n);
        while (l < r) {
            ll mid = l + r >> 1;
            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }
        printf("%lld\n", r);
    }
    return 0;
}