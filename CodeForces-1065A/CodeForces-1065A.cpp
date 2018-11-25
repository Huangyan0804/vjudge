#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int s, a, b, c;
        cin >> s >> a >> b >> c;
        long long ans = 0, num;
        num = s / c;
        long long free = num / a * b;
        ans = num + free;
        cout << ans << endl;
    }

    return 0;
}