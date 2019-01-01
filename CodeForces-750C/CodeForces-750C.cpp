#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 20;
int n, c[N], d[N];
bool check(int x)
{
    for (int i = 0; i < n; i++) {
        if (d[i] == 1 && x < 1900)
            return true;
        if (d[i] == 2 && x >= 1900)
            return false;
        x += c[i];
    }
    return true;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> d[i];
    }
    int l = -1e9, r = 1e9;
    int ans;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
            ans = mid;
        } else
            r = mid - 1;
    }
    bool imp = false;
    if (ans >= 1e9) {
        cout << "Infinity" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (d[i] == 1 && ans < 1900) {
            imp = true;
            break;
        }
        if (d[i] == 2 && ans >= 1900) {
            imp = true;
            break;
        }
        ans += c[i];
    }
    if (imp)
        cout << "Impossible" << endl;
    else
        cout << ans << endl;
    return 0;
}