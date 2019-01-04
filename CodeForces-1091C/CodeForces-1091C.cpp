#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    set<ll> ans, num;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            num.insert(i);
            num.insert(n / i);
        }
    }
    for (auto i : num) {
        ll m = n / i;
        ll x = 1 + (m - 1) * i;
        ll res = (1 + x) * m / 2;
        ans.insert(res);
    }
    for (auto i : ans) {
        cout << i << ' ';
    }
    return 0;
}
