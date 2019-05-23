#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 205;
bool vis[N][N];
struct node2 {
    int x, y;
} a[N];
bool cmp(node2 a, node2 b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
struct node {
    int x1, y1, x2, y2;
} b[N * 2];
int judge(node a, node b)
{
    if (a.x1 > b.x2 || a.y1 > b.y2)
        return 1;
    if (b.x1 > a.x2 || b.y1 > a.y2)
        return 1;
    //  b ╟Э a
    if (a.x1 > b.x1 && a.y1 > b.y1 && a.x2 < b.x2 && a.y2 < b.y2)
        return 2;
    if (b.x1 > a.x1 && b.y1 > a.y1 && b.x2 < a.x2 && b.y2 < a.y2)
        return 3;
    return 0;
}
int get_area(node a)
{
    return (a.x2 - a.x1) * (a.y2 - a.y1);
}
int main()
{
    int n;
    while (cin >> n && n) {
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < n; i++) {
            cin >> a[i].x >> a[i].y;
            vis[a[i].x][a[i].y] = 1;
        }
        sort(a, a + n, cmp);
        int k = 0;
        // вСоб срио
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[j].x > a[i].x && a[j].y > a[i].y) {
                    if (vis[a[i].x][a[j].y] && vis[a[j].x][a[i].y]) {
                        b[k].x1 = a[i].x;
                        b[k].x2 = a[j].x;
                        b[k].y1 = a[i].y;
                        b[k].y2 = a[j].y;
                        k++;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                int sum = 0;
                int op = 0;
                op = judge(b[i], b[j]);
                if (op == 1) {
                    sum = get_area(b[i]) + get_area(b[j]);
                } else if (op == 2) {
                    sum = get_area(b[j]);
                } else if (op == 3) {
                    sum = get_area(b[i]);
                }
                ans = max(ans, sum);
            }
        }
        if (ans)
            cout << ans << endl;
        else
            cout << "imp" << endl;
    }
    return 0;
}