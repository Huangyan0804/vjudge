#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
bool box[750][750];
void draw(int n, int x, int y)
{
    if (n == 1) {
        box[x][y] = true;
        return;
    }
    for (int i = 1; i <= 5; i++) {
        int len = (int)pow(3.0, n - 2);
        if (i == 1) {
            draw(n - 1, x, y);
        } else if (i == 2) {
            draw(n - 1, x + 2 * len, y);
        } else if (i == 3) {
            draw(n - 1, x + len, y + len);
        } else if (i == 4) {
            draw(n - 1, x, y + 2 * len);
        } else if (i == 5) {
            draw(n - 1, x + 2 * len, y + 2 * len);
        }
    }
}
int main()
{

    int n;
    while (cin >> n && n != -1) {
        draw(n, 0, 0);
        int len = (int)pow(3.0, n - 1);
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (box[i][j])
                    printf("X");
                else
                    printf(" ");
            }
            puts("");
        }
        puts("-");
    }
    return 0;
}