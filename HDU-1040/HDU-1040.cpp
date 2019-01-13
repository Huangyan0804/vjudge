#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    while (getline(cin, s)) {
        if (s == "ENDOFINPUT")
            break;
        else if (s != "START" && s != "END") {
            int n = s.length();
            for (int i = 0; i < n; i++) {
                if (isalpha(s[i])) {
                    s[i] -= 5;
                    if (s[i] < 65)
                        s[i] += 26;
                }
                cout << s[i];
            }
            cout << endl;
        }
    }
    return 0;
}