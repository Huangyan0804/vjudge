#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct S {
    int id, pos;
    char d;
    string print = "";
};
bool cmp(S a, S b)
{
    return a.pos < b.pos;
}
int main()
{
    int T;
    cin >> T;
    int cnt = 0;
    while (T--) {
        S ant[10001];
        int L, t, n;
        cin >> L >> t >> n;
        for (int i = 0; i < n; i++) {
            cin >> ant[i].pos >> ant[i].d;
            ant[i].id = i;
        }
        sort(ant, ant + n, cmp);
        for (int i = 0; i < n; i++) {
            if (ant[i].d == 'L') {
                ant[i].pos -= t;
            } else if (ant[i].d == 'R') {
                ant[i].pos += t;
            }
        }

        int ord[10001];
        for (int i = 0; i < n; i++) {
            ord[ant[i].id] = i;
        }
        sort(ant, ant + n, cmp);
        ant[n].pos = ant[n - 1].pos + 1;
        printf("Case #%d\n", ++cnt);
        for (int k = 0; k < n; k++) {
            int i = ord[k];
            if (ant[i].pos < 0 || ant[i].pos > L) {
                ant[i].print = "Fell off";
            } else if (ant[i].pos == ant[i + 1].pos) {
                ant[i].print += to_string(ant[i].pos) + " Turning";
                ant[i + 1].print += to_string(ant[i + 1].pos) + " Turning";
                i++;
            } else {
                ant[i].print += to_string(ant[i].pos) + ' ' + ant[i].d;
            }
            cout << ant[ord[i]].print << endl;
        }
        cout << endl;
    }
    return 0;
}