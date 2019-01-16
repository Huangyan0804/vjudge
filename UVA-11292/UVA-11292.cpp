#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int m, n;
    while (cin >> n >> m && (n || m)) {
        int a[20001], b[20001];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        sort(a, a + n);
        sort(b, b + m);
        int ans = 0;
        int i, j;
        for (i = 0, j = 0; j < m; j++) {
            if (b[j] >= a[i]) {
                i++;
                ans += b[j];
                if (i == n) {
                    break;
                }
            }
        }
        if (i < n) {
            cout << "Loowater is doomed!" << endl;
        } else
            cout << ans << endl;
    }
    return 0;
}