#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int n;
char str[1000010];
int Next[1000010];
void get_next()
{
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && str[i] != str[j + 1])
            j = Next[j];
        if (str[i] == str[j + 1])
            j++;
        Next[i] = j;
    }
}
int main()
{
    int T = 1;
    while (cin >> n && n) {
        scanf("%s", str + 1);
        get_next();
        printf("Test case #%d\n", T++);
        for (int i = 2; i <= n; i++) {
            int x = i - Next[i];
            if (x != i && i % x == 0) {
                printf("%d %d\n", i, i / x);
            }
        }
        puts("");
    }
    return 0;
}