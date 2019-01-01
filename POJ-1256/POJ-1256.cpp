#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int cmp(char a, char b)
{
    if (tolower(a) != tolower(b))
        return tolower(a) < tolower(b);
    else
        return a < b;
}
int main()
{
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        sort(s.begin(), s.end(), cmp);
        do {
            cout << s << endl;
        } while (next_permutation(s.begin(), s.end(), cmp));
    }
    return 0;
}