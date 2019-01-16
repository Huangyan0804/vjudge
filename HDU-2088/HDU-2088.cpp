#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    int a[100];
    bool flag = false;
    while (~scanf("%d", &n) && n != 0) {
        if (flag == false)
            flag = true;
        else
            printf("\n");
        int sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        int avrg = sum / n, ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < avrg)
                ans += avrg - a[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}