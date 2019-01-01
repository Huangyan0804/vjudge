#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int MAXN = 100005;
int c[MAXN];
int lowbit(int x)
{
    return x & -x;
}
int sum(int x)
{
    int res = 0;
    while (x > 0) {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}
void add(int x, int y)
{
    while (x < MAXN) {
        c[x] += y;
        x += lowbit(x);
    }
}
int main()
{
    int n;
    while (cin >> n && n) {
        memset(c, 0, sizeof(c));
        int a, b;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            add(a, 1);
            add(b + 1, -1);
        }
        cout << sum(1);
        for (int i = 2; i <= n; i++) {
            cout << ' ' << sum(i);
        }
        cout << endl;
    }
    return 0;
}