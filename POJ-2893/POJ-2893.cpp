#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
#define scanff(n) scanf("%d", &n);
const int N = 1000005;
int a[N], b[N], n, m;
ll ans = 0;
void msort(int l, int r)
{
    if (l == r)
        return;
    ll mid = (l + r) >> 1;
    msort(l, mid);
    msort(mid + 1, r);
    ll i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else {
            ans += mid - i + 1;
            b[k++] = a[j++];
        }
    }
    while (i <= mid) {
        b[k++] = a[i++];
    }
    while (j <= r) {
        b[k++] = a[j++];
    }
    for (ll x = l; x <= r; x++)
        a[x] = b[x];
}
int main()
{
    while (cin >> n >> m && (n || m)) {
        ans = 0;
        int col, p = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x;
                scanff(x);
                if (x) {
                    a[++p] = x;
                } else {
                    col = n - i - 1;
                }
            }
        }
        msort(1, p);
        if (m % 2) {
            if (ans % 2)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        } else {
            if (col % 2 != ans % 2)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
    return 0;
}