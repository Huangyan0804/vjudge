#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    int cnt = 1;
    while (cin >> n && n) {
        cout << "Game " << cnt++ << ':' << endl;
        int a[1001], b[1001];
        int flag[10] = { 0 };
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            flag[a[i]] = 1;
        }
        // int tobreak = 1;
        while (1) {
            int x = 0, y = 0;
            int vis1[1001] = { 0 }; // 相等
            int vis2[1001] = { 0 }; // 位置不同
            int zero = 0;
            for (int i = 0; i < n; i++) {
                cin >> b[i];
                if (b[i] == 0)
                    zero++;
            }
            if (zero == n) {
                break;
            }
            for (int i = 0; i < n; i++) {
                if (b[i] == a[i]) {
                    x++;
                    vis1[i] = 1;
                    vis2[i] = 1;
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    if (a[i] == b[j] && !vis1[i] && !vis2[j]) {
                        y++;
                        vis2[j] = 1;
                        vis1[i] = 1;
                    }
                }
            }

            printf("    (%d,%d)\n", x, y);
        }
    }
    return 0;
}
