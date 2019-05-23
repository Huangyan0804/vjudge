#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;
#define scanff(n) scanf("%d", &n)
const int N = 27010;
int n, m, k, len;
int a[N], b[N], l[N], r[N], sum[N], ans[N], pos[N];
struct node {
    int l, r;
    int id, blk;
    bool operator<(const node& a) const
    {
        if (blk == a.blk)
            return r < a.r;
        return blk < a.blk;
    }
} q[N];
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
    int res = 0;
    while (x > 0) {
        res += sum[x];
        x -= lowbit(x);
    }
    return res;
}
int main()
{

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanff(a[i]);
        b[i] = a[i];
    }
    int blk = sqrt(n);
    sort(a + 1, a + 1 + n);
    len = unique(a + 1, a + 1 + n) - (a + 1);
    for (int i = 1; i <= n; i++) {
        l[i] = lower_bound(a + 1, a + 1 + len, b[i] - k) - a;
        r[i] = upper_bound(a + 1, a + 1 + len, b[i] + k) - a - 1;
        pos[i] = lower_bound(a + 1, a + 1 + len, b[i]) - a;
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].id = i;
        q[i].blk = q[i].l / blk;
    }
    sort(q + 1, q + 1 + m);
    int Ans = 0;
    int ll = 1, rr = 0;
    for (int i = 1; i <= m; i++) {
        while (ll > q[i].l) {
            ll--;
            Ans += query(r[ll]) - query(l[ll] - 1);
            update(pos[ll], 1);
        }
        while (ll < q[i].l) {
            update(pos[ll], -1);
            Ans -= query(r[ll]) - query(l[ll] - 1);
            ll++;
        }
        while (rr > q[i].r) {
            update(pos[rr], -1);
            Ans -= query(r[rr]) - query(l[rr] - 1);
            rr--;
        }
        while (rr < q[i].r) {
            rr++;
            Ans += query(r[rr]) - query(l[rr] - 1);
            update(pos[rr], 1);
        }
        ans[q[i].id] = Ans;
    }
    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}