#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct P {
    int l, r, x;
    bool operator<(const P& b) const
    {
        if (r == b.r)
            return l > b.l;
        return r > b.r;
    }
} cow[50005];
bool cmp(P a, P b)
{
    if (a.l == b.l)
        return a.r < b.r;
    return a.l < b.l;
}
priority_queue<P> q;
int ans[50005];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cow[i].l >> cow[i].r;
        cow[i].x = i;
    }
    sort(cow, cow + n, cmp);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!q.empty() && q.top().r < cow[i].l) {
            ans[cow[i].x] = ans[q.top().x];
            q.pop();
        } else {
            cnt++;
            ans[cow[i].x] = cnt;
        }
        q.push(cow[i]);
    }
    cout << cnt << endl;
    for(int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}