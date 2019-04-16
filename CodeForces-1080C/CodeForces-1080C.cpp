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
    //���½ǵķ���Ϊ��ɫ
    if ((x1 + y1) & 1)
        return n * m / 2;
    //���½Ƿ���Ϊ��ɫ
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
        //�����һ�������к�ɫ�����������������Ϳ�ɰ�ɫ
        ll b1 = paintb(x1, y1, x2, y2);
        //�ڶ��������а�ɫ�����������������Ϳ�ɺ�ɫ
        ll w2 = paintw(x3, y3, x4, y4);
        //�ܹ��İ�ɫ���������
        ll answ = (n * m + 1) / 2 + b1 - w2;
        //�����������Ƿ��ཻ���ཻ�Ĳ��ֶ����ɺ�ɫ������Ҫ������֮ǰ������İ�ɫ�ķ��������
        ll minx = min(x2, x4), miny = min(y2, y4);
        ll maxx = max(x1, x3), maxy = max(y1, y3);
        if (minx >= maxx && miny >= maxy)
            answ -= paintb(maxx, maxy, minx, miny);
        cout << answ << " " << n * m - answ << endl;
    }
    return 0;
}