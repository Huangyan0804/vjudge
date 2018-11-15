#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int c[1000001];
int main()
{
    vector<int> v;
    int n;
    while (cin >> n) {
        v.clear();
        v.push_back(0);
        long long money, sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> money;
            v.push_back(money);
            sum += money;
        }
        long long M = sum / n;

        c[0] = 0;
        for (int i = 1; i < n; i++) {
            c[i] = v[i] + c[i - 1] - M;
        }
        sort(c, c + n);
        long long mid = c[n / 2];
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += abs(mid - c[i]);
        }
        cout << ans << endl;
    }
    return 0;
}