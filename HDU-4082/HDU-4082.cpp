#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

const int N = 1010;
bool vis[300][300];
struct point {
    int x, y;
} a[N];
struct trangle {
    int a, b, c;
} b[N];
bool cmp(point a, point b)
{
    return a.x != b.x ? a.x < b.x : a.y < b.y;
}
bool check(point a, point b, point c)
{
    if ((b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y) == 0)
        return false;
    return true;
}
int dist(point a, point b)
{
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}
int main()
{
    int n;
    while (cin >> n && n) {
        memset(vis, 0, sizeof vis);
        int m = 0;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            if (vis[x + 100][y + 100] == 0) {
                vis[x + 100][y + 100] = 1;
                a[m].x = x;
                a[m].y = y;
                m++;
            }
        }
        sort(a, a + m, cmp);
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                for (int k = j + 1; k < m; k++) {
                    if (check(a[i], a[j], a[k])) {
                        int temp[3];
                        temp[0] = dist(a[i], a[j]);
                        temp[1] = dist(a[i], a[k]);
                        temp[2] = dist(a[j], a[k]);
                        sort(temp, temp + 3);
                        b[cnt].a = temp[0], b[cnt].b = temp[1], b[cnt].c = temp[2];
                        cnt++;
                    }
                }
            }
        }
        int num[N] = { 0 };
        int ans = 0;
        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < cnt; j++) {
                if (b[i].a * b[j].b == b[j].a * b[i].b
                    && b[i].a * b[j].c == b[j].a * b[i].c) {
                    num[i]++;
                    ans = max(ans, num[i]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}