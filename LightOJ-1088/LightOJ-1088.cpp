#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int sum[N], a[N], b[N], len;
int lowbit(int x)
{
    return x & -x;
}
void update(int x, int val)
{
    while (x <= len) {
        sum[x] += val;
        x += lowbit(x);
    }
}
int query(int x)
{
    int ans = 0;
    while (x > 0) {
        ans += sum[x];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    int t, n, q, T = 1;
    scanf("%d", &t);
    while (t--) {
        memset(sum, 0, sizeof sum);
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(a + 1, a + n + 1);
        len = unique(a + 1, a + 1 + n) - a - 1;
        for (int i = 1; i <= n; i++) {
            int pos = lower_bound(a + 1, a + 1 + n, b[i]) - a;
            update(pos, 1);
        }
        int ans = 0;
        printf("Case %d:\n", T++);
        while (q--) {
            int l, r;
            scanf("%d%d", &l, &r);
            int ll = lower_bound(a + 1, a + 1 + len, l) - a;
            int rr = upper_bound(a + 1, a + 1 + len, r) - a - 1;
            ans = query(rr) - query(ll - 1);
            printf("%d\n", ans);
        }
    }
    return 0;
}