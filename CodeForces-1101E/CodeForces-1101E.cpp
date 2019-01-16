#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    char op[5];
    int x, y;
    int maxx = 0, maxy = 0;
    for (int i = 0; i < n; i++) {
        scanf("%S%d%d", op, &x, &y);
        if (x < y) {
            swap(x, y);
        }
        if (op[0] == '+') {
            maxx = max(maxx, x);
            maxy = max(maxy, y);
        } else {
            int flag = false;
            if (x >= maxx && y >= maxy) {
                flag = true;
            }
            if (flag) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
    return 0;
}