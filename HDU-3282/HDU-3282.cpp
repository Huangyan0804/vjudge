#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    priority_queue<int> q1, q2;
    int id, m;
    scanf("%d%d", &id, &m);
    int a;
    scanf("%d", &a);
    q2.push(-a);
    printf("%d %d\n", id, (m + 1) / 2);
    if (m != 1)
      printf("%d ", a);
    else
      printf("%d\n", a);
    int cnt = 1;
    for (int i = 2; i <= m; i++) {
      scanf("%d", &a);
      if (a < -q2.top())
        q1.push(a);
      else
        q2.push(-a);
      int s = q1.size();
      if (s > i / 2) {
        q2.push(-q1.top());
        q1.pop();
      }
      if (s < i / 2) {
        q1.push(-q2.top());
        q2.pop();
      }
      if (i % 2) {
        if (++cnt % 10 == 0 || i == m)
          printf("%d\n", -q2.top());
        else
          printf("%d ", -q2.top());
      }
    }
    // puts("");
  }
  return 0;
}