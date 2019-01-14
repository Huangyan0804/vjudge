#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        string minstr = s;
        for (int i = 0; i < n; i++) {
            string tempstr = s.substr(i) + s.substr(0, i);
            minstr = min(minstr, tempstr);
        }
        cout << minstr << endl;
    }
    return 0;
}