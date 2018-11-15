#include <algorithm>
#include <iostream>
using namespace std;
struct S {
    int b, j;
};
bool cmp(S a, S b)
{
    return a.j > b.j;
}
int main()
{
    int n;
    int cnt = 0;
    while (cin >> n && n) {
        S a[1001];
        for (int i = 0; i < n; i++)
            cin >> a[i].b >> a[i].j;
        sort(a, a + n, cmp);
        int ans = 0, s = 0;
        for (int i = 0; i < n; i++) {
            s += a[i].b;
            ans = max(ans, s + a[i].j);
        }
        cout << "Case " << ++cnt << ": " << ans << endl;
    }
    return 0;
}