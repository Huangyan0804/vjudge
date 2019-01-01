#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    int nn = n;
    for (int i = 0; i < 31; i++) {
        if (nn & (1 << i))
            v.push_back(1 << i);
    }
    if (k >= v.size() && k <= n) {
        cout << "YES" << endl;
        int i = 0;
        while (k > v.size()) {

            if (v[i] > 1) {
                v[i] /= 2;
                v.push_back(v[i]);
            } else {
                i++;
            }
        }
        for (auto i : v) {
            cout << i << ' ';
        }

    } else {
        cout << "NO" << endl;
    }
    return 0;
}