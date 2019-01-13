#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct student {
    int p;
    string t;
    int id;
    int score;
};
bool cmp1(student a, student b)
{
    if (a.p != b.p)
        return a.p > b.p;
    else
        return a.t < b.t;
}
bool cmp2(student a, student b)
{
    return a.id < b.id;
}
int main()
{
    int n;
    while (cin >> n && n > 0) {
        student a[101];
        string t;
        int p, num[6] = { 0 };
        for (int i = 0; i < n; i++) {
            cin >> p >> t;
            num[p]++;
            a[i].p = p;
            a[i].t = t;
            a[i].id = i;
        }
        //num[4] += num[5], num[3] += num[4], num[2] += num[3], num[1] += num[2];
        int sum[6];
        sum[5] = num[5];
        sum[4] = sum[5] + num[4];
        sum[3] = sum[4] + num[3];
        sum[2] = sum[3] + num[2];
        sum[1] = sum[2] + num[1];
        sort(a, a + n, cmp1);

        for (int i = 0; i < n; i++) {
            if (a[i].p == 5) {
                a[i].score = 100;
            } else if (a[i].p == 4) {
                a[i].score = 90;
                if (i - sum[5] < num[4] / 2)
                    a[i].score += 5;
            } else if (a[i].p == 3) {
                a[i].score = 80;
                if (i - sum[4] < num[3] / 2)
                    a[i].score += 5;
            } else if (a[i].p == 2) {
                a[i].score = 70;
                if (i - sum[3] < num[2] / 2)
                    a[i].score += 5;
            } else if (a[i].p == 1) {
                a[i].score = 60;
                if (i - sum[2] < num[1] / 2)
                    a[i].score += 5;
            } else if (a[i].p == 0) {
                a[i].score = 50;
            }
        }
        sort(a, a + n, cmp2);
        for (int i = 0; i < n; i++) {
            cout << a[i].score << endl;
        }
        cout << endl;
    }
    return 0;
}