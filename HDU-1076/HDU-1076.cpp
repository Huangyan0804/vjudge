#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int y, n;
        cin >> y >> n;
        for (; n > 0; y++) {
            if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
                n--;
            }
        }
        cout << y - 1 << endl;
    }
    return 0;
}