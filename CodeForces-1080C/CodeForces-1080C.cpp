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
const int inf = INT_MAX;
const int N = 1;
ll paintw(ll x1, ll y1, ll x2, ll y2)
{
    ll n = x2 - x1 + 1;
    ll m = y2 - y1 + 1;
    //左下角的方块为黑色
    if ((x1 + y1) & 1)
        return n * m / 2;
    //左下角方块为白色
    else
        return (n * m + 1) / 2;
}

ll paintb(ll x1, ll y1, ll x2, ll y2)
{
    ll n = x2 - x1 + 1;
    ll m = y2 - y1 + 1;
    return n * m - paintw(x1, y1, x2, y2);
}
int main()
{
    int t;
    scanff(t);
    while (t--) {
        ll n, m;
        ll x1, y1, x2, y2;
        ll x3, y3, x4, y4;
        cin >> n >> m;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x3 >> y3 >> x4 >> y4;
        //计算第一块区域中黑色方块的数量，即将被涂成白色
        ll b1 = paintb(x1, y1, x2, y2);
        //第二块区域中白色方块的数量，即将被涂成黑色
        ll w2 = paintw(x3, y3, x4, y4);
        //总共的白色方块的数量
        ll answ = (n * m + 1) / 2 + b1 - w2;
        //看两个矩形是否相交，相交的部分都会变成黑色，所以要计算变黑之前，里面的白色的方块的数量
        ll minx = min(x2, x4), miny = min(y2, y4);
        ll maxx = max(x1, x3), maxy = max(y1, y3);
        if (minx >= maxx && miny >= maxy)
            answ -= paintb(maxx, maxy, minx, miny);
        cout << answ << " " << n * m - answ << endl;
    }
    return 0;
}