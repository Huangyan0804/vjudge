#include <iostream>
using namespace std;
int main()
{
    int n, d, u;
    while (cin >> n >> u >> d && (n + d + u != 0)) {
        int ans = 0;
        while (n > 0) {
            n -= u;
            ans++;
            if (n > 0) {
                ans++;
                n += d;
            }
        }
        cout << ans << endl;
    }
    return 0;
}