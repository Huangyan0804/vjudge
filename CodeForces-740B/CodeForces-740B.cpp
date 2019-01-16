#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
struct S {
    int l, r;
} s;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a;
    int temp;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        a.push_back(temp);
    }
    int l, r, sum;
    vector<S> plan;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        sum = 0;
        cin >> l >> r;
        for (int j = l - 1; j < r; j++) {
            sum += a[j];
        }
        if (sum >= 0) {
            s.l = l - 1;
            s.r = r - 1;
            plan.push_back(s);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < plan.size(); j++) {
            if (i >= plan[j].l && i <= plan[j].r)
                ans += a[i];
        }
    }
    cout << ans << endl;
    return 0;
}