#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;

int main()
{
    ll a, b, c, d;
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%I64d%I64d%I64d%I64d", &a, &b, &c, &d);
        ll ans = 0;
        for (ll cur = 1LL << 62; cur > 0; cur >>= 1) {
            ll aa = cur & a, bb = cur & b;
            ll cc = cur & c, dd = cur & d;
            if (aa == bb) { // x ��ǰλֻ��ȡһ������
                if (cc == dd) { // y ��ǰֻ��ȡһ������
                    ans |= cc ^ aa;
                } else { // y ��ǰ��ȡ��������
                    ans |= cur;
                    if (aa == 0) { //���x��һλֻ��ȡ0����y�ض�ȡ1
                        c &= cur; //y��λ�Ժ��λ��������00...00
                    } else { //���x��һλֻ��ȡ1����y�ض�ȡ0
                        d |= cur - 1; //y��λ�Ժ��λ��������11...11
                    }
                }
            } else { // x ��ǰ��ȡ��������
                ans |= cur;
                if (cc == dd) { // y ��ȡһ��
                    if (cc == 0) { //���y��һλֻ��ȡ0����x�ض�ȡ1
                        a &= cur;
                    } else { //���y��һλֻ��ȡ1����x�ض�ȡ0
                        b |= cur - 1;
                    }
                } else { // y ȡ����
                    ans |= cur - 1;
                    break;
                }
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}