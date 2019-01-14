#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[101];
    int cnt[2] = { 0 };
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1)
            cnt[0]++;
        else
            cnt[1]++;
    }
    int maxn = 0;
    for (int i = 0; i < n; i++) {
        int tempa = cnt[0], tempb = cnt[1];
        for (int j = i % k; j < n; j += k) {
            if (a[j] == 1)
                tempa--;
            else
                tempb--;
        }
        maxn = max(maxn, abs(tempa - tempb));
    }
    cout << maxn << endl;
    return 0;
}