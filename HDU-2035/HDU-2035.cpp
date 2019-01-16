#include <algorithm>
#include <iostream>
using namespace std;
int qmi(int a, int b, int c)
{
    int t = a, res = 1;
    while (b) {
        if (b & 1)
            res = res * t % c;
        b >>= 1;
        t = t * t % c;
    }
    return res;
}
int main()
{
    int a, b;
    while (cin >> a >> b && (a || b)) {
        cout << qmi(a, b, 1000) << endl;
    }
    return 0;
}