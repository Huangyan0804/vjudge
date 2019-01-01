#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct Pot {
    int a, b;
    int step;
    string ans;
} pot, front;
int vis[1001][1001];
string caozuo[7] = { "", "FILL(1)", "FILL(2)", "DROP(1)", "DROP(2)",
    "POUR(1,2)", "POUR(2,1)" };
int a, b, c;
queue<Pot> q;

bool bfs()
{
    pot.a = 0;
    pot.b = 0;
    pot.step = 0;
    pot.ans = "";
    vis[pot.a][pot.b] = 1;
    q.push(pot);
    while (!q.empty()) {
        front = q.front();
        q.pop();
        if (front.a == c || front.b == c) {
            return true;
        }
        for (int i = 1; i <= 6; i++) {
            if (i == 1) { // fill a
                pot.a = a;
                pot.b = front.b;
            } else if (i == 2) {
                pot.a = front.a;
                pot.b = b;
            } else if (i == 3) { // drop a
                pot.a = 0;
                pot.b = front.b;
            } else if (i == 4) {
                pot.a = front.a;
                pot.b = 0;
            } else if (i == 5) { // pour a->b
                int temp = b - front.b;
                if (temp < front.a) {
                    pot.b = b;
                    pot.a = front.a - temp;
                } else {
                    pot.b = front.b + front.a;
                    pot.a = 0;
                }
            } else {
                int temp = a - front.a;
                if (temp < front.b) {
                    pot.a = a;
                    pot.b = front.b - temp;
                } else {
                    pot.a = front.a + front.b;
                    pot.b = 0;
                }
            }
            if (!vis[pot.a][pot.b]) {
                pot.step = front.step + 1;
                pot.ans = front.ans + char(i + '0');
                vis[pot.a][pot.b] = 1;
                q.push(pot);
            }
        }
    }
    return false;
}
int main()
{
    cin >> a >> b >> c;
    if (bfs()) {
        cout << front.step << endl;
        int len = front.ans.length();
        for (int i = 0; i < len; i++) {
            cout << caozuo[front.ans[i] - '0'] << endl;
        }
    } else {
        cout << "impossible" << endl;
    }
    return 0;
}
