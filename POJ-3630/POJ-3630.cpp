#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
const int N = 10010;
int n, m;
char str[10 * N][10];
int son[10 * N][10], cnt[10 * N], idx;
bool flag;
void insert(char* x)
{
    int p = 0;
    int len = strlen(x);
    for (int i = 0; i < len; i++) {
        int& s = son[p][x[i] - '0'];
        if (!s) {
            s = ++idx;
        }
        p = s;
        cnt[p]++;
    }
}
bool query(char* x)
{
    int len = strlen(x), p = 0;
    for (int i = 0; i < len; i++) {
        // int& s = son[p][x[i] - '0'];
        p = son[p][x[i] - '0'];
        if (cnt[p] == 1)
            return false;
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        memset(cnt, 0, sizeof cnt);
        memset(son, 0, sizeof son);
        idx = 0;
        cin >> n;
        flag = true;
        for (int i = 0; i < n; i++) {
            cin >> str[i];
            insert(str[i]);
        }
        for (int i = 0; i < n; i++) {
            if (query(str[i])) {
                flag = false;
                break;
            }
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}