#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int n, c;
int a[100005];
bool judge(int x)
{
    int cnt = 1, cur = 0;
    for (int i = 1; i < n; i++) {
        cur += a[i] - a[i - 1];
        if (cur >= x) {
            cur = 0;
            cnt++;
        }
    }
    if (cnt >= c)
        return true;
    else
        return false;
}
int binary(int minn, int maxn)
{
    int l = 1, r = maxn - minn;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (judge(mid))
            l = mid;
        else
            r = mid - 1;
    }
    return r;
}

int main()
{
    scanf("%d %d", &n, &c);

    int maxn = 0, minn = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        minn = min(minn, a[i]);
        maxn = max(maxn, a[i]);
    }
    sort(a, a + n);
    int ans = binary(minn, maxn);
    printf("%d\n", ans);
    return 0;
}