#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
char str[20];
int s[20][20], temp[20][20];
int ans;
bool vis[20];
void zhuan(int x, int y)
{
    for (int i = 4 * x - 3, n = 4 * y - 3; i <= 4 * x; i++, n++) {
        for (int j = 4 * y - 3, m = 4 * x; j <= 4 * y; j++, m--) {
            temp[i][j] = s[m][n];
        }
    }
    for (int i = 4 * x - 3; i <= 4 * x; i++) {
        for (int j = 4 * y - 3; j <= 4 * y; j++) {
            s[i][j] = temp[i][j];
        }
    }
}
bool check(int x, int y)
{
    for (int i = 4 * x - 3; i < 4 * x; i++) {
        memset(vis, 0, sizeof(vis));
        for (int j = 1; j <= 4 * y; j++) {
            if (vis[s[i][j]])
                return 0;
            vis[s[i][j]] = 1;
        }
    }
    for (int j = 4 * y - 3; j <= 4 * y; j++) {
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= 4 * x; i++) {
            if (vis[s[i][j]])
                return 0;
            vis[s[i][j]] = 1;
        }
    }
    return 1;
}
void dfs(int x, int y, int cnt)
{
    if (x > 4) {
        ans = min(ans, cnt);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (i)
            zhuan(x, y);
        if (check(x, y)) {
            if (y == 4)
                dfs(x + 1, 1, cnt + i);
            else
                dfs(x, y + 1, cnt + i);
        }
    }
    zhuan(x, y);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        for (int i = 1; i <= 16; i++) {
            scanf("%s", str + 1);
            for (int j = 1; j <= 16; j++) {
                if (str[j] >= '0' && str[j] <= '9') {
                    s[i][j] = str[j] - '0';
                } else {
                    s[i][j] = str[j] - 'A' + 10;
                }
            }
        }
        ans = 1e9;
        dfs(1, 1, 0);
        printf("%d\n", ans);
    }
    return 0;
}