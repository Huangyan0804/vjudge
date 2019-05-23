#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define scanff(n) scanf("%d", &n)
vector<vector<int>> v;
int main()
{
    int n, m, p, q;
    while (~scanf("%d%d", &n, &m)) {
        v = vector<vector<int>>(n + 5, vector<int>(m + 5));
        int x1, y1, x2, y2;
        scanff(p);
        for (int i = 0; i < p; i++) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            v[x1][y1]++;
            v[x2 + 1][y2 + 1]++;
            v[x1][y2 + 1]--;
            v[x2 + 1][y1]--;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                v[i][j] = v[i][j] + v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
                //if (v[i][j] > 1)
                // v[i][j] = 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (v[i][j] > 0)
                    v[i][j] = 1;
                v[i][j] = v[i][j] + v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
            }
        }
        scanff(q);
        for (int i = 0; i < q; i++) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            int area = (x2 - x1 + 1) * (y2 - y1 + 1);
            int area2 = v[x2][y2] - v[x1 - 1][y2] - v[x2][y1 - 1] + v[x1 - 1][y1 - 1];
            if (area2 >= area) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
    return 0;
}