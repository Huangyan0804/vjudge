#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int m, n;
    while (cin >> m >> n) {
        int col1, col2, row11, row12, row21, row22;
        col1 = sqrt(m - 1) + 1;
        col2 = sqrt(n - 1) + 1;
        row11 = (m - (col1 - 1) * (col1 - 1) + 1) / 2;
        row12 = (n - (col2 - 1) * (col2 - 1) + 1) / 2;
        row21 = (col1 * col1 - m) / 2 + 1;
        row22 = (col2 * col2 - n) / 2 + 1;
        int ans = abs(col1 - col2) + abs(row11 - row12) + abs(row21 - row22);
        cout << ans << endl;
    }
    return 0;
}
