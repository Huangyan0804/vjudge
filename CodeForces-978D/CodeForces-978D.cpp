#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
const int N = 100001;
int a[N], b[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 100000000;
    int def;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int cnt = abs(i) + abs(j);
            int flag = 1;
            b[0] = a[0] + i;
            b[1] = a[1] + j;
            def = b[1] - b[0];
            for (int k = 2; k < n; k++) {
                b[k] = b[k - 1] + def;
                if (abs(b[k] - a[k]) > 1) {
                    flag = 0;
                    break;
                } else {
                    if (b[k] != a[k])
                        cnt++;
                }
            }
            if (flag) {
                ans = min(ans, cnt);
            }
        }
    }
    if (ans != 100000000) {
        cout << ans << endl;
    } else {
        cout << "-1" << endl;
    }
    return 0;
}