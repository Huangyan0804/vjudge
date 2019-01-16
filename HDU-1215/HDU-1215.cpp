#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                ans += i;
                if (i != 1 && i * i != n) {
                    ans += n / i;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}