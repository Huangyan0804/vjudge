#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define scanff(n) scanf("%d", &n)
int map[10][10];
int map1[10][10];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
void turn(int x, int y)
{
    // 翻动x，y及其周围
    map[x][y] ^= 1;
    for (int i = 0; i < 4; i++) {
        map[x + dx[i]][y + dy[i]] ^= 1;
    }
}
int main()
{
    char s[10];
    for (int i = 1; i <= 4; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= 4; j++) {
            if (s[j] == 'b')
                map1[i][j] = 1;
            else
                map1[i][j] = 0;
        }
    }
    //memcpy(map,map1,sizeof map1);
    int ans = 0x3f3f3f3f;
    // 枚举第一排的状态
    for (int i = 0; i < 1 << 4; i++) {
        memcpy(map, map1, sizeof map1);
        int cnt = 0;
        for (int j = 1; j <= 4; j++) {
            if (i & (1 << (j - 1))) { // 取位
                turn(1, j);
                cnt++;
            }
        }
        // 全亮
        for (int j = 1; j < 4; j++) {
            for (int k = 1; k <= 4; k++) {
                if (!map[j][k]) {
                    turn(j + 1, k);
                    cnt++;
                }
            }
        }
        bool flag = true;
        // 直接判断最后一行是否全亮

        for (int k = 1; k <= 4; k++) {
            if (!map[4][k]) {
                flag = false;
            }
        }

        if (flag)
            ans = min(ans, cnt);
    }
    //memcpy(map,map1,sizeof map1);
    for (int i = 0; i < 1 << 4; i++) {
        memcpy(map, map1, sizeof map1);
        int cnt = 0;
        for (int j = 1; j <= 4; j++) {
            if (i & (1 << (j - 1))) {
                turn(1, j);
                cnt++;
            }
        }
        // 全灭
        for (int j = 1; j < 4; j++) {
            for (int k = 1; k <= 4; k++) {
                if (map[j][k]) {
                    turn(j + 1, k);
                    cnt++;
                }
            }
        }
        bool flag = true;

        for (int k = 1; k <= 4; k++) {
            if (map[4][k]) {
                flag = false;
            }
        }

        if (flag)
            ans = min(ans, cnt);
    }
    if (ans != 0x3f3f3f3f)
        cout << ans << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}