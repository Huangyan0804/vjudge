#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
#define scanff(n) scanf("%d", &n)
typedef long long ll;
const int N = 3 * 1e5 + 10;
const int M = 15000005;
int a[N];
int prime[M], div1[15000005];
int Gcd(int n, int m)
{
    return m == 0 ? n : Gcd(m, n % m);
}
map<int, int> mp, CNT;
void init()
{
    for (int i = 2; i < M; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            div1[i] = i;
        }
        for (int j = 1; j <= prime[0] && prime[j] * i < M; j++) {
            prime[prime[j] * i] = 1;
            div1[prime[j] * i] = prime[j];
            if (i % prime[j] == 0)
                break;
        }
    }
}
int main()
{
    int n;

    scanff(n);
    scanff(a[0]);
    int gcd = a[0];
    for (int i = 1; i < n; i++) {
        scanff(a[i]);
        gcd = Gcd(gcd, a[i]);
    }
    int maxn = 0, ans = 0;
    init();
    for (int i = 0; i < n; i++) {
        a[i] /= gcd;
        int x = a[i];
        while (x > 1) {
            int j = div1[x];
            if (x % j == 0) {
                CNT[j]++;
                while (x % j == 0 && x != 1) {
                    x /= j;
                }
            }
        }
    }
    for (auto i : CNT) {
        ans = max(ans, i.second);
    }
    if (ans != 0) {
        printf("%d\n", n - ans);
    } else {
        printf("-1\n");
    }
    return 0;
}