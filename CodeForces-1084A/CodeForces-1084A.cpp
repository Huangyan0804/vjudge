#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[105];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        int temp = 0;
        for (int j = 1; j <= n; j++) {
            temp = temp + a[j] * (abs(i - j) + (j - 1) + (i - 1) + (i - 1) + (j - 1) + abs(i - j));
        }
        ans = min(ans, temp);
    }
    cout << ans << endl;
    return 0;
}