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
            if (aa == bb) { // x 当前位只能取一个数字
                if (cc == dd) { // y 当前只能取一个数字
                    ans |= cc ^ aa;
                } else { // y 当前能取两个数字
                    ans |= cur;
                    if (aa == 0) { //如果x这一位只能取0，则y必定取1
                        c &= cur; //y该位以后的位的下限是00...00
                    } else { //如果x这一位只能取1，则y必定取0
                        d |= cur - 1; //y该位以后的位的上限是11...11
                    }
                }
            } else { // x 当前能取两个数字
                ans |= cur;
                if (cc == dd) { // y 能取一个
                    if (cc == 0) { //如果y这一位只能取0，则x必定取1
                        a &= cur;
                    } else { //如果y这一位只能取1，则x必定取0
                        b |= cur - 1;
                    }
                } else { // y 取两个
                    ans |= cur - 1;
                    break;
                }
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}