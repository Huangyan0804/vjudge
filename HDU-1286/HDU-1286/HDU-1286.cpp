#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int eular(int n)
{
    int ans = 1;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            n /= i;
            ans *= i - 1;
            while (n % i == 0) {
                n /= i;
                ans *= i;
            }
        }
    }
    if (n > 1)
        ans *= n - 1;
    return ans;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", eular(n));
    }
    return 0;
}