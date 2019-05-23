#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    string a, b;
    while (cin >> a >> b) {
        if (a.front() != b.front() || a.back() != b.back()) {
            cout << "No" << endl;
            continue;
        }
        if (a == b) {
            cout << "Equal" << endl;
            continue;
        }
        map<char, int> mp;
        for (int i = 0; i < a.length() - 1; i++) {
            mp[a[i]]++;
        }
        for (int i = 0; i < b.length() - 1; i++) {
            mp[b[i]]--;
        }
        bool flag = true;
        for (auto i : mp) {
            if (i.second != 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}