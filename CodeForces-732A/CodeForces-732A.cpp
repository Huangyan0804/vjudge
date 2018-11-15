#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int k, r;
    cin >> k >> r;
    int money, sum;
    for (int i = 1; i <= 10; i++) {
        money = k * i;
        int leftmoney = money % 10;
        if (leftmoney == r || leftmoney == 0) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}