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

int e[1001][1001], dist[1001], book[1001];
int main()
{
    int t;
    scanff(t);
    int cnt = 1;
    while (t--) {
        int n, m;
        scanff(n), scanff(m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (i == j)
                    e[i][j] = 0;
                else
                    e[i][j] = -1;
            }
        for (int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if (e[a][b] < c) {
                e[a][b] = c;
                e[b][a] = c;
            }
        }
        for (int i = 1; i <= n; i++) {
            dist[i] = e[1][i];
            book[i] = 0;
        }
        int minn = -1;
        book[1] = 1;
        int u = -1;
        for (int i = 1; i <= n; i++) {
            minn = -inf;
            for (int j = 1; j <= n; j++) {
                if (book[j] == 0 && dist[j] > minn) {
                    minn = dist[j];
                    u = j;
                }
            }
            if (u != -1) {
                book[u] = 1;
                for (int v = 1; v <= n; v++) {
                    if (e[u][v] != inf)
                        dist[v] = max(dist[v], min(dist[u], e[u][v]));
                }
            }
        }
        printf("Scenario #%d:\n%d\n\n", cnt++, dist[n]);
    }
    return 0;
}