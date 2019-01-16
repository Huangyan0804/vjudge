#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
void del(string& s, string c)
{
    int pos = s.find(c);
    if (pos == s.npos) {
        cout << "-1" << endl;
        exit(0);
    } else {
        s.erase(0, pos + 1);
    }
}
int main()
{
    string s;
    cin >> s;
    del(s, "[");
    del(s, ":");
    reverse(s.begin(), s.end());
    del(s, "]");
    del(s, ":");
    cout << count(s.begin(), s.end(), '|') + 4 << endl;
    return 0;
}