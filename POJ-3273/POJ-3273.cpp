#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int n, m;
int a[100005];
bool judge(int x)
{
    int money = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        money += a[i];
        if (money > x) {
            i--;
            money = 0;
            cnt++;
        }
    }
    if (money != 0)
        cnt++;
    if (cnt > m)
        return true;
    else
        return false;
}
int binary(int maxn, int sum)
{
    int l = maxn, r = sum;
    while (l < r) {
        int mid = (l + r + 0ll) / 2;
        if (judge(mid))
            l = mid + 1;
        else
            r = mid;
    }
    return r;
}

int main()
{
    cin >> n >> m;

    int maxn = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        maxn = max(maxn, a[i]);
    }
    int ans = binary(maxn, sum);
    cout << ans << endl;
    return 0;
}