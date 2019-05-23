#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define scanff(n) scanf("%d", &n)

typedef long long ll;
const int N = 2e6 + 10;
ll a[N], ans[N], sum[N], Ans;
int n, m, k;
struct node {
    int l, r, id, block;
    bool operator<(const node& a) const
    {
        if (block == a.block)
            return r < a.r;
        return block < a.block;
    }
} op[N];
void add(int x)
{
    Ans += sum[a[x] ^ k];
    sum[a[x]]++;
}
void del(int x)
{
    sum[a[x]]--;
    Ans -= sum[a[x] ^ k];
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    int block = (int)sqrt(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = a[i] ^ a[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &op[i].l, &op[i].r);
        op[i].id = i;
        op[i].block = op[i].l / block;
    }
    sort(op + 1, op + 1 + m);

    int l = 1, r = 0;
    sum[0] = 1;
    Ans = 0;
    for (int i = 1; i <= m; i++) {
        while (l < op[i].l)
            del(l - 1), l++;
        while (l > op[i].l)
            l--, add(l - 1);
        while (r < op[i].r)
            add(++r);
        while (r > op[i].r)
            del(r--);
        ans[op[i].id] = Ans;
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}