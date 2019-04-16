#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <limits.h>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define scanff(n) scanf("%d", &n)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1005;
vector<int> v[N];
int n, m, x, y, man[N];
bool flag = true;
void dfs(int x)
{
    for (int i = 0; i < v[x].size(); i++) {
        int r = v[x][i];
        if (man[r] == man[x]) {
            flag = false;
            return;
        }
        if (man[r] == 0) {
            man[r] = man[x] == 1 ? -1 : 1;
            dfs(r);
        }
    }
}
int main()
{
    while (scanf("%d%d%d%d", &n, &m, &x, &y) == 4) {
        for (int i = 1; i <= n; i++) {
            v[i].clear();
            man[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for (int i = 0; i < x; i++) {
            int num;
            scanff(num);
            man[num] = 1;
        }
        for (int i = 0; i < y; i++) {
            int num;
            scanff(num);
            man[num] = -1;
        }
        if (x == 0 && y == 0) {
            printf("NO\n");
            continue;
        }
        flag = true;
        for (int i = 1; i <= n; i++) {
            if (man[i] != 0 && flag) {
                dfs(i);
            }
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}