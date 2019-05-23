#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1000010;
int son[N / 2][26], cnt[N], idx;
char s[N];
void insert()
{
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int& x = son[p][s[i] - 'a'];
        if (!x)
            x = ++idx;
        p = x;
    }
    cnt[p]++;
}
int query()
{
    int p = 0, res = 0;
    for (int i = 0; s[i]; i++) {
        int& x = son[p][s[i] - 'a'];
        if (!x)
            break;
        p = x;
        res += cnt[p];
    }
    return res;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    while (n--) {
        scanf("%s", s);
        insert();
    }
    while (m--) {
        scanf("%s", s);
        printf("%d\n", query());
    }
    return 0;
}