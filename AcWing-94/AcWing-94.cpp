#include <iostream>
using namespace std;
int n;
int ans[10];
bool vis[10];
void fun(int x)
{
    if (x == n + 1) {
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i])
            continue;
        vis[i] = true;
        ans[x] = i;
        fun(x + 1);
        vis[i] = false;
    }
}
int main()
{
    cin >> n;
    fun(1);
    return 0;
}