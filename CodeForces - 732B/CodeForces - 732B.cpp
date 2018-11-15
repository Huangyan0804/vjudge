#include <algorithm>
#include <iostream>
using namespace std;
int a[100000];
int main()
{
    int n, k;
    int ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int temp = k - (a[i] + a[i - 1]);
        if (a[i] + a[i - 1] < k) {
            a[i] += temp;
            ans += temp;
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}