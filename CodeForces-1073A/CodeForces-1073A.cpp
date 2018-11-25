#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
bool fun(string s)
{
    int len = s.length();
    int a[26] = { 0 };
    int mid = len / 2;
    for (int i = 0; i < len; i++) {
        a[s[i] - 'a']++;
        if (a[s[i] - 'a'] > mid) {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    int flag = 0;
    string temp;
    for (int i = 0; i < n && !flag; i++) {
        for (int j = i + 1; j < n && !flag; j++) {
            temp = s.substr(i, j - i + 1);
            if (fun(temp)) {
                flag = 1;
            }
        }
    }
    if (flag) {
        cout << "YES" << endl;

        cout << temp << endl;

    } else {
        cout << "NO" << endl;
    }
    return 0;
}