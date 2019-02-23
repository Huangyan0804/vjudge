#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int state = 0;
    char op;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            op = getchar();
            if (op == '+')
                state |= 1 << (i * 4 + j);
        }
        getchar();
    }

    for (int k = 1; k < (1 << 17); k++) {
        vector<pair<int, int>> ans;
        int tempstate = state;
        for (int i = 0; i < 16; i++) {
            if ((k >> i) & 1) {
                int x = i / 4, y = i % 4, pos;
                ans.push_back(make_pair(x, y));
                for (int j = 0; j < 4; j++) {
                    state ^= 1 << (x * 4 + j);
                }
                for (int j = 0; j < 4; j++) {
                    pos = 1 << (j * 4 + y);
                    if (pos != 1 << i) {
                        state ^= pos;
                    }
                }
            }
        }
        if (state == 0) {
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i++) {
                printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
            }
            break;
        }
        state = tempstate;
    }
    return 0;
}