#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, a[200];
    cin >> n;
    int sum1 = 0, k = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum1 += a[i];
        k = max(k, a[i]);
    }

    int flag = 0;
    while (!flag) {
        int sum2 = 0;
        for (int i = 0; i < n; i++) {
            sum2 += k - a[i];
        }
        if (sum2 > sum1) {
            flag = 1;
        } else {
            k++;
        }
    }
    cout << k << endl;
    return 0;
}