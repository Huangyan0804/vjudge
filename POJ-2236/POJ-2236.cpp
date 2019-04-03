#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define scanff(n) scanf("%d", &n)
int n, d;
struct node {
    int x, y, father;
    bool ok;
} com[1005];
bool dist(node a, node b)
{
    double ans = sqrt((double)(a.x - b.x) * (a.x - b.x)
        + (double)(a.y - b.y) * (a.y - b.y));
    if (ans <= (double)d)
        return true;
    else
        return false;
}
int find(int a)
{
    int temp = a;
    while (temp != com[temp].father) {
        temp = com[temp].father;
    }
    int i = a, j;
    while (i != temp) {
        j = com[i].father;
        com[i].father = temp;
        i = j;
    }
    return temp;
}
void join(int a, int b)
{
    int f1 = find(a), f2 = find(b);
    if (f1 != f2)
        com[f1].father = f2;
}
int main()
{

    scanff(n), scanff(d);
    for (int i = 1; i <= n; i++) {
        scanff(com[i].x), scanff(com[i].y);
        com[i].father = i;
        com[i].ok = false;
    }
    char op;
    while (cin >> op) {
        if (op == 'O') {
            int a;
            cin >> a;
            com[a].ok = true;
            for (int i = 1; i <= n; i++) {
                if (i != a && dist(com[a], com[i]) && com[i].ok) {
                    join(a, i);
                }
            }
        } else {
            int a, b;
            cin >> a >> b;
            int f1 = find(a), f2 = find(b);
            if (f1 == f2) {
                cout << "SUCCESS" << endl;
            } else {
                cout << "FAIL" << endl;
            }
        }
    }
    return 0;
}