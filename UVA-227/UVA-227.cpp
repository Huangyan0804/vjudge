#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
bool check(int a, int b)
{
    if (a >= 5 || a < 0 || b >= 5 || b < 0)
        return false;
    return true;
}
int main()
{
    int t = 0;
    while (++t) {
        char c[6][6];
        int x, y;
        gets(c[0]);
        if (c[0][0] == 'Z')
            break;
        if (t != 1)
            printf("\n");
        gets(c[1]);
        gets(c[2]);
        gets(c[3]);
        gets(c[4]);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (c[i][j] == ' ') {
                    x = i;
                    y = j;
                }
            }
        }

        //getchar();
        string cmd, cmd1;
        bool flag = true;
        getline(cin, cmd);
        int len = cmd.length();
        while (cmd[len - 1] != '0') {
            getline(cin, cmd1);
            cmd += cmd1;
            len = cmd.length();
        }
        for (int i = 0; i < cmd.length(); i++) {
            int tempx = -1, tempy = -1;
            if (cmd[i] == 'A') {
                tempx = x - 1, tempy = y;
            } else if (cmd[i] == 'B') {
                tempx = x + 1, tempy = y;
            } else if (cmd[i] == 'L') {
                tempx = x, tempy = y - 1;
            } else if (cmd[i] == 'R') {
                tempx = x, tempy = y + 1;
            } else if (cmd[i] == '0') {
                break;
            }
            if (check(tempx, tempy)) {
                swap(c[x][y], c[tempx][tempy]);
                x = tempx, y = tempy;
            } else {
                flag = false;
                break;
            }
        }

        printf("Puzzle #%d:\n", t);
        if (flag) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 4; j++) {
                    printf("%c ", c[i][j]);
                }
                printf("%c\n", c[i][4]);
            }
        } else {
            printf("This puzzle has no final configuration.\n");
        }
    }
    return 0;
}
