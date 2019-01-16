#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        long long num, sum = 0, maxn = 0;
        scanf("%lld", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &num);
            maxn = max(maxn, num);
            sum += num;
        }
        long long temp = sum - maxn + 1;
        if (temp >= maxn) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}