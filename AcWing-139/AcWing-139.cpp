#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef unsigned long long ull;
const int N = 2000010, base = 131;
char s[N];
ull hl[N], hr[N], p[N];
int m = 0;
ull get(ull h[], int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}
int main()
{
    int T = 1;
    while (scanf("%s", s + 1)) {
        if (s[1] == 'E')
            break;
        int n = strlen(s + 1);
        for (int i = 2 * n; i >= 0; i -= 2) {
            s[i] = s[i / 2];
            s[i - 1] = 'z' + 1;
        }
        n *= 2;
        p[0] = 1;
        for (int i = 1, j = n; i <= n; j--, i++) {
            hl[i] = hl[i - 1] * base + s[i] - 'a' + 1;
            hr[i] = hr[i - 1] * base + s[j] - 'a' + 1;
            p[i] = p[i - 1] * base;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int l = 0, r = min(i - 1, n - i);
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (get(hl, i - mid, i - 1) != get(hr, n - (i + mid) + 1, n - (i + 1) + 1))
                    r = mid - 1;
                else
                    l = mid;
            }
            if (s[i - l] <= 'z')
                ans = max(ans, l + 1);
            else
                ans = max(ans, l);
        }
        printf("Case %d: %d\n", T++, ans);
    }
    return 0;
}