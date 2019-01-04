#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    int x, y;
    scanf("%d", &n);
    ll sumx = 0, sumy = 0;
    for (int i = 0; i < 2 * n; i++) {
        scanf("%d %d", &x, &y);
        sumx += x;
        sumy += y;
    }
    cout << sumx / n << ' ' << sumy / n << endl;

    return 0;
}