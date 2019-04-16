#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
#define scanff(n) scanf("%d", &n)
int n, k, r;
const int N = 105;
const int inf = 0x3f3f3f3f;
struct node {
    int to, len, cost;
    node(int dd, int ll, int tt)
    {
        to = dd;
        len = ll;
        cost = tt;
    }
    bool operator<(const node& b) const
    {
        return len > b.len;
    }
};
vector<node> v[N];
int vis[N], dis[N];
int res = -1;
void dijkstra()
{
    priority_queue<node> q;
    q.push(node(1, 0, 0));
    while (!q.empty()) {
        node front = q.top();
        q.pop();
        if (front.to == n) {
            res = front.len;
            return;
        }
        for (int i = 0; i < v[front.to].size(); i++) {
            node& x = v[front.to][i];
            if (front.cost + x.cost <= k) {
                q.push(node(x.to, x.len + front.len, x.cost + front.cost));
            }
        }
    }
}
int main()
{
    scanf("%d%d%d", &k, &n, &r);
    for (int i = 0; i < r; i++) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        v[a].push_back(node(b, c, d));
    }
    dijkstra();
    cout << res << endl;
    return 0;
}