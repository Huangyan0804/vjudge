#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int T = 1;
    while (t--) {
        printf("Case #%d: ", T++);
        int n;
        cin >> n;
        if (n < 7) {
            cout << "Draw" << endl;
            continue;
        } else {
            if (n % 2 == 1) {
                cout << "Panda" << endl;
                continue;
            } else {
                if (n >= 16) {
                    cout << "Sheep" << endl;
                    continue;
                } else {
                    cout << "Draw" << endl;
                    continue;
                }
            }
        }
    }
    return 0;
}