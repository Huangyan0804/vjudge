#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
typedef unsigned long long ull;
const int N = 1000010, base = 131;
char s[N];
ull h[N], p[N];
ull get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}
int main()
{
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    p[0] = 1;
    for (int i = 1; i <= len; i++) {
        h[i] = h[i - 1] * base + s[i] - 'a' + 1;
        p[i] = p[i - 1] * base;
    }
    int n;
    cin >> n;
    while (n--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (get(l1, r1) == get(l2, r2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
abcbabcbabcba
abacacbaaaaba