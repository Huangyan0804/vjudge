#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef long long ll;
#define scanff(n) scanf("%d", &n)
const int N = 2e5 + 10;
ll a[N];
ll k, n, m, p;
int qmi(ll a, ll b)
{
    ll ans = 1;
    while (b) {
        if (b & 1)
            ans = ans * a;
        b >>= 1;
        a = a * a;
    }
    return ans;
}
int main()
{

    while (~scanf("%lld%lld%lld%lld", &k, &m, &n, &p)) {
        for (int i = 0; i < k; i++) {
            scanf("%lld", &a[i]);
        }
        sort(a, a + k);
        ll len = qmi(n, m) - 1;
        ll ans = 0;
        int x = 0;
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < qmi(n, i); j++) {
                ans = (ans + ((a[x] % p) * ((1ll - qmi(n, m - i)) / (1ll - n) % p)) % p) % p;
                x++;
            }
        }
        printf("%lld\n", ans);
    }
    //  (1-qmi(n, m - i - 1)) / (1-q)
    return 0;
}