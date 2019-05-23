#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 100010;
struct node {
    int l, r;
    ll sum;
#define l(p) tree[p].l
#define r(p) tree[p].r
#define sum(p) tree[p].sum
} tree[N * 4];
ll a[N];
int n, m;
void build(int p, int l, int r)
{
    l(p) = l, r(p) = r, sum(p) = 0;
    if (l == r) {
        sum(p) = a[r];
        return;
    }
    int mid = l + r >> 1;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    sum(p) = sum(p * 2) + sum(p * 2 + 1);
}
void change(int p, int l, int r)
{
    if (sum(p) == r(p) - l(p) + 1) {
        return;
    }
    if (l(p) == r(p)) {
        sum(p) = (int)sqrt(sum(p));
        return;
    }
    int mid = l(p) + r(p) >> 1;
    if (l <= mid)
        change(p * 2, l, r);
    if (r > mid)
        change(p * 2 + 1, l, r);
    sum(p) = sum(p * 2) + sum(p * 2 + 1);
}
ll query(int p, int l, int r)
{
    if (l <= l(p) && r >= r(p)) {
        return sum(p);
    }
    ll ans = 0;
    int mid = l(p) + r(p) >> 1;
    if (l <= mid)
        ans += query(p * 2, l, r);
    if (r > mid)
        ans += query(p * 2 + 1, l, r);
    return ans;
}
int main()
{
    int T = 0;
    while (~scanf("%d", &n)) {
        printf("Case #%d:\n", ++T);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        build(1, 1, n);
        scanf("%d", &m);
        while (m--) {
            int op, l, r;
            scanf("%d%d%d", &op, &l, &r);
            if (l > r)
                swap(l, r);
            if (op == 0) {
                change(1, l, r);
            } else {
                printf("%lld\n", query(1, l, r));
            }
        }
        puts("");
    }
    return 0;
}