#include <algorithm>
#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
const int N = 100002;
long long a[N];

int main()
{
    int n, m, l;
    cin >> n >> m >> l;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int t;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > l && a[i - 1] <= l) {
            ans++;
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        if (t == 0) {
            printf("%d\n", ans);
        } else if (t == 1) {
            int p, d;
            scanf("%d %d", &p, &d);
            a[p] += d;
            //   1 1 2 2 2 1 2 1 1
            if (a[p - 1] > l && a[p + 1] > l && a[p] > l && a[p] - d <= l)
                ans--;
            else if (a[p - 1] <= l && a[p + 1] <= l && a[p] > l && a[p] - d <= l)
                ans++;
        }
    }
    return 0;
}