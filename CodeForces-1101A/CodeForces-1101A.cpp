#include <iostream>
using namespace std;
int main()
{
    int q;
    cin >> q;
    while (q--) {
        int l, r, d;
        cin >> l >> r >> d;
        int ans = d;
        if (d < l || d > r) {
            ans = d;
        } else {
            ans = (r / d + 1) * d;
        }
        cout << ans << endl;
    }
    return 0;
}