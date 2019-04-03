#include <algorithm>
#include <iostream>
using namespace std;
#define scanff(n) scanf("%d", &n)
int pre[1005];
int find(int x)
{
    int r = x;
    while (pre[r] != r) {
        r = pre[r];
    }
    int i = x, j;
    while (i != r) {
        j = pre[i];
        pre[i] = r;
        i = j;
    }
    return r;
}
void join(int x, int y)
{
    int a = find(x), b = find(y);
    if (a == b)
        return;
    pre[a] = b;
    return;
}
int main()
{
    int n, m;
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++)
            pre[i] = i;
        cin >> m;
        int a, b;
        for (int i = 0; i < m; i++) {
            scanff(a), scanff(b);
            join(a, b);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (pre[i] == i)
                ans++;
        }
        cout << ans - 1 << endl;
    }
    return 0;
}