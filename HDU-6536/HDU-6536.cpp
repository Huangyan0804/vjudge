#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;
#define scanff(n) scanf("%d", &n)
const int N = 2e5 + 10;
char s[N];
int main()
{
    int n;
    while (~scanff(n)) {
        scanf("%s", s);
        int cnt[10] = { 0 };
        for (int i = 0; i < n; i++) {
            if (s[i] == 'x') {
                cnt[0]++;
            } else if (s[i] == 't' && cnt[0] > cnt[1]) {
                cnt[1]++;
            } else if (s[i] == 'C' && cnt[1] > cnt[2]) {
                cnt[2]++;
            } else if (s[i] == 'p' && cnt[2] > cnt[3]) {
                cnt[3]++;
            } else if (s[i] == 'c' && cnt[3] > cnt[4]) {
                cnt[4]++;
            }
        }
        printf("%d\n", cnt[4]);
    }
    return 0;
}