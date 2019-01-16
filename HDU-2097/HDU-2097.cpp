#include <iostream>
using namespace std;
int fun(int a, int n)
{
    int ans = 0;
    int num = a;
    while (num) {
        ans += num % n;
        num /= n;
    }
    return ans;
}
int main()
{
    int n;
    while (cin >> n && n) {
        int a = fun(n, 10);
        int b = fun(n, 12);
        int c = fun(n, 16);
        if (a == b && b == c) {
            printf("%d is a Sky Number.\n", n);
        } else
            printf("%d is not a Sky Number.\n", n);
    }

    return 0;
}