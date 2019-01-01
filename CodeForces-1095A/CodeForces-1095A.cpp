#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    string s;
    cin >> t;
    cin >> s;
    string ans;
    int cnt = 1;
    for (int i = 0; i < t; i += cnt) {
        ans += s[i];
        cnt++;
    }
    cout << ans << endl;
    return 0;
}