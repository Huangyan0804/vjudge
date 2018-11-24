#include <iostream>
using namespace std;
int num[100000000];

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int ans = k <= 1 ? 5 : k + 5;
        cout << ans << endl;
    }
    return 0;
}