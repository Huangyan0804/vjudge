#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
char m[7][7];
int mp[7][7];
int dx[5] = { -1, 0, 1, 0, 0 },
    dy[5] = { 0, -1, 0, 1, 0 };
bool check()
{
    for (int j = 0; j < 5; j++) {
        if (mp[4][j] == 0)
            return false;
    }
    return true;
}
void turn(int x, int y)
{
    for (int i = 0; i < 5; i++) {
        if (x + dx[i] >= 0 && x + dx[i] < 5 && y + dy[i] >= 0 && y + dy[i] < 5)
            mp[x + dx[i]][y + dy[i]] ^= 1;
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--) {
        int ans = 100;
        memset(mp, 0, sizeof(mp));
        memset(m, 0, sizeof(m));
        for (int i = 0; i < 5; i++) {
            scanf("%s", m[i]);
        }

        for (int i = 0; i < (1 << 5); i++) {

            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    mp[j][k] = m[j][k] - '0';
                }
            }
            int cnt = 0;
            for (int j = 0; j < 5; j++) {
                if (i & (1 << j)) {
                    cnt++;
                    turn(0, j);
                }
            }
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 5; k++) {
                    if (mp[j][k] == 0) {
                        cnt++;
                        turn(j + 1, k);
                    }
                }
            }
            if (check())
                ans = min(ans, cnt);
        }
        if (ans <= 6) {
            cout << ans << endl;
        } else {
            cout << "-1" << endl;
        }
    }
    return 0;
}