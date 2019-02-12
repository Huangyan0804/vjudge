#include <algorithm>
#include <iostream>
using namespace std;
#define scanff(n) scanf("%d", &n)
typedef pair<int, int> P;
P cow[2505], spf[2505];
bool cmp(P a, P b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}
int main()
{
    int n, m;
    scanff(n);
    scanff(m);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &cow[i].first, &cow[i].second);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &spf[i].first, &spf[i].second);
    }
    sort(cow, cow + n, cmp);
    sort(spf, spf + m, cmp);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cow[i].first <= spf[j].first
                && cow[i].second >= spf[j].first
                && spf[j].second) {
                ans++;
                spf[j].second--;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}