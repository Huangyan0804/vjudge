#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
const int N = 10010;
int n, m, t;
int a[N], b[N], c[N];
void merge()
{
    priority_queue<PII, vector<PII>, greater<PII>> q;
    for (int i = 0; i < n; i++) {
        q.push({ a[0] + b[i], 0 });
    }
    for (int i = 0; i < n; i++) {
        auto t = q.top();
        q.pop();
        c[i] = t.first;
        q.push({ t.first - a[t.second] + a[t.second + 1], t.second + 1 });
    }
    for (int i = 0; i < n; i++)
        a[i] = c[i];
}
int main()
{
    cin >> t;
    while (t--) {
        cin >> m >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> b[j];
            }
            sort(b, b + n);
            merge();
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        puts("");
    }
    return 0;
}