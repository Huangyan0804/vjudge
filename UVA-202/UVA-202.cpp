#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
void fun(int a, int b)
{
    int arr1[4000] = { 0 }, arr2[4000] = { 0 }, arr3[4000] = { 0 };
    int cur = 0;
    printf("%d/%d = ", a, b);
    arr1[cur++] = a / b;
    a %= b;
    while (!arr3[a] && a) {
        arr3[a] = cur;
        arr2[cur] = a;
        arr1[cur] = a * 10 / b;
        a = a * 10 % b;
        cur++;
    }
    printf("%d.", arr1[0]);
    for (int i = 1; i < cur && i <= 50; i++) {
        if (a && arr2[i] == a) {
            printf("(");
        }
        printf("%d", arr1[i]);
    }
    if (!a) {
        printf("(0");
    }
    if (cur > 50) {
        printf("...");
    }
    printf(")\n");
    int ans = cur - arr3[a];
    if (a == 0)
        ans = 1;
    printf("   %d = number of digits in repeating cycle\n", ans);
}
int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) {
        fun(a, b);
        printf("\n");
    }
    return 0;
}