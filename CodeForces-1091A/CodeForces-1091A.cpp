#include <iostream>
using namespace std;
int main()
{
    int y, b, r;
    cin >> y >> b >> r;
    if (b > y + 1) {
        b = y + 1;
    } else if (b < y + 1) {
        y = b - 1;
    }
    if (r > b + 1) {
        r = b + 1;
    } else if (b > r - 1) {
        b = r - 1;
    }
    if (b > y + 1) {
        b = y + 1;
    } else if (b < y + 1) {
        y = b - 1;
    }
    cout << y + b + r << endl;
    return 0;
}