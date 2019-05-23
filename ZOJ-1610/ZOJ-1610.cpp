#include <algorithm>
#include <cstdio>
#include <cstring>
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
using namespace std;
int const MAX = 8005;
int const CON = 8000;
int col[MAX << 2], num[MAX];
int getcol[MAX], n;

void Build()
{
    memset(num, 0, sizeof(num));
    memset(col, -1, sizeof(col));
    memset(getcol, -1, sizeof(getcol));
}

void PushDown(int rt)
{
    if (col[rt] != -1) {
        col[rt << 1] = col[rt];
        col[rt << 1 | 1] = col[rt];
        col[rt] = -1;
    }
    return;
}

void Update(int L, int R, int c, int l, int r, int rt)
{
    if (L <= l && r <= R) {
        col[rt] = c;
        return;
    }
    int mid = (l + r) >> 1;
    PushDown(rt);
    if (L <= mid)
        Update(L, R, c, lson);
    if (mid < R)
        Update(L, R, c, rson);
    return;
}

void Query(int l, int r, int rt)
{
    if (col[rt] != -1) {
        for (int i = l; i <= r; i++)
            getcol[i] = col[rt];
        return;
    }
    if (l < r && col[rt] == -1) {
        int mid = (l + r) >> 1;
        Query(lson);
        Query(rson);
    }
    return;
}

void Solve()
{
    if (getcol[0] != -1)
        num[getcol[0]]++;
    for (int i = 1; i <= CON; i++)
        if (getcol[i] != -1 && getcol[i] != getcol[i - 1])
            num[getcol[i]]++;
    for (int i = 0; i <= CON; i++)
        if (num[i])
            printf("%d %d\n", i, num[i]);
    printf("\n");
}

int main()
{
    while (scanf("%d", &n) != EOF) {
        Build();
        for (int i = 0; i < n; i++) {
            int l, r, c;
            scanf("%d %d %d", &l, &r, &c);
            Update(l + 1, r, c, 1, CON, 1);
        }
        Query(1, CON, 1);
        Solve();
    }
}