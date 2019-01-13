#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n && n) {
        int a[102];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int cur = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > cur) {
                ans += 6 * (a[i] - cur);
            } else if (a[i] < cur) {
                ans += 4 * (cur - a[i]);
            }
            cur = a[i];
            ans += 5;
        }
        cout << ans << endl;
    }
    return 0;
}