#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
#define scanff(n) scanf("%d", &n);
const int N = 500005;
int a[N], b[N], n;
ll ans = 0;
void msort(int l, int r)
{
    if (l == r)
        return;
    ll mid = (l + r) >> 1;
    msort(l, mid);
    msort(mid + 1, r);
    ll i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else {
            ans += mid - i + 1;
            b[k++] = a[j++];
        }
    }
    while (i <= mid) {
        b[k++] = a[i++];
    }
    while (j <= r) {
        b[k++] = a[j++];
    }
    for (ll x = l; x <= r; x++)
        a[x] = b[x];
}
int main()
{
    while (cin >> n && n) {
        ans = 0;
        for (int i = 1; i <= n; i++)
            scanff(a[i]);
        msort(1, n);
        printf("%lld\n", ans);
    }
    return 0;
}