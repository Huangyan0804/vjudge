#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 100010;
int n;
int son[30 * N][2], idx, a[N];
void insert(int x)
{
    int p = 0;
    for (int i = 30; ~i; i--) {
        int& s = son[p][x >> i & 1];
        if (!s)
            s = ++idx;
        p = s;
    }
}
int query(int x)
{
    int p = 0, res = 0;
    for (int i = 30; ~i; i--) {
        int s = x >> i & 1;
        if (son[p][!s]) {
            res += 1 << i;
            p = son[p][!s];
        } else
            p = son[p][s];
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, query(a[i]));
    }
    cout << res << endl;
    return 0;
}