#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int main()
{

    int n, num;
    map<int, int> mp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        mp[num]++;
    }
    int ans;
    if (n != 2) {
        auto maxit = mp.end(), minit = mp.begin();
        int max1, max2, min1, min2;
        maxit--;
        max1 = maxit->first;
        if (maxit->second > 1) {
            max2 = max1;
        } else {
            maxit--;
            max2 = maxit->first;
        }
        min1 = minit->first;
        if (minit->second > 1) {
            min2 = min1;
        } else {
            minit++;
            min2 = minit->first;
        }
        ans = min(max1 - min2, max2 - min1);
    } else {
        ans = 0;
    }
    cout << ans << endl;
    return 0;
}