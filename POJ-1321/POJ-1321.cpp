#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int N = 10;
char map[N][N];
int vis[N][N];
int n, k, ans;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
void dfs(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= n)
        return;
    if (map[x][y] == '#')
        return;
    if (vis[x][y])
        return;
    vis[x][y] = 1;
    if (x == n - 1)
        ans++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        for (int i = 0)
            map[x + 1][y] = '#';
        dfs(nx, ny);
    }
}
int main()
{
    while (cin >> n >> k) {
        ans = 0;
        if (n == -1 && k == -1)
            break;
        for (int i = 0; i < n; i++) {
            dfs(0, i);
        }
    }
    return 0;
}