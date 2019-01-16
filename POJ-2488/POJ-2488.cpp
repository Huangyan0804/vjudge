#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 27;
bool vis[N][N];
int ansx[N];
int ansy[N];
int n, m;
int flag = 0;
string ans;
int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[] = { -1, 1, -2, 2, -2, 2, -1, 1 };
bool ok(int x, int y)
{
    if (x < 0 || x >= m || y < 0 || y >= n)
        return false;
    if (vis[x][y])
        return false;
    return true;
}
void dfs(int x, int y, int step)
{
    if (vis[x][y])
        return;
    if (step == n * m) {
        for (int i = 1; i <= n * m; i++) {
            cout << char(ansx[i] + 65) << ansy[i] + 1;
        }
        flag = 1;
        return;
    }
    vis[x][y] = true;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (ok(nx, ny)) {
            ansx[step + 1] = nx;
            ansy[step + 1] = ny;
            dfs(nx, ny, step + 1);
        }
    }
}
void start()
{
    memset(vis, false, sizeof(vis));
    memset(ansx, 0, sizeof(ansx));
    memset(ansy, 0, sizeof(ansy));
    flag = 0;
}
int main()
{
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        cin >> n >> m;
        start();
        cout << "Scenario #" << k << ":" << endl;
        ansx[1] = 0;
        ansy[1] = 0;
        dfs(0, 0, 1);
        if (!flag)
            cout << "impossible" << endl;
        cout << endl;
    }
    return 0;
}