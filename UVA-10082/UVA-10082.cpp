#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    string s;
    while (getline(cin, s)) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int pos = a.find(s[i]);
            if (pos != a.npos) {
                cout << a[pos - 1];
            } else {
                cout << s[i];
            }
        }
        cout << endl;
    }
    return 0;
}