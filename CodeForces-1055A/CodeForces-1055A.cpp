#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int n, s;
int a[1001], b[1001];
bool vis[1001][1001];
string ans;
void fun(int x, int y)
{ // x -> y
    if (vis[x][y])
        return;
    if (x < 0 || x >= n)
        return;
    if (y == s - 1) {
        ans = "YES";
        return;
    }
    vis[x][y] = true;
    //向右
    for (int i = y + 1; i < n; i++) {
        if (a[y] == 1 && a[i] == 1) {
            fun(y, i);
        }
    }
    //向左
    for (int i = y - 1; i >= 0; i--) {
        if (b[i] == 1 && b[y] == 1) {
            fun(y, i);
        }
    }
}
int main()
{

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ans = "NO";
    fun(0, 0);
    if (s == 1)
        ans = "YES";
    cout << ans << endl;

    return 0;
}