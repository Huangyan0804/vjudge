#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int a[10001][10];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= 10000; i++) {
        for (int j = 1; j <= i; j++) {
            int tempnum = j;
            while (tempnum) {
                int tempmod = tempnum % 10;
                a[i][tempmod]++;
                tempnum /= 10;
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << a[n][0];
        for (int i = 1; i <= 9; i++) {
            cout << ' ' << a[n][i];
        }
        cout << endl;
    }
    return 0;
}