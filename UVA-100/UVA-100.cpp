#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, m;
    while (cin >> n >> m) {
        cout << n << ' ' << m << ' ';
        if (m < n) {
            swap(m, n);
        }
        int maxn = 0;
        for (int i = n; i <= m; i++) {
            int num = i, cnt = 0;
            while (num != 1) {
                if (num & 1) {
                    num = num * 3 + 1;
                } else {
                    num /= 2;
                }
                cnt++;
            }
            maxn = max(cnt, maxn);
        }
        cout << maxn + 1 << endl;
    }
    return 0;
}