#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n, k;
    cin >> n >> k;
    char cz;
    long long num;
    long long leftnum = k, leavekid = 0;
    for (int i = 0; i < n; i++) {
        cin >> cz >> num;
        if (cz == '+') {
            leftnum += num;
        } else {
            if (leftnum < num) {
                leavekid++;
            } else {
                leftnum -= num;
            }
        }
    }
    cout << leftnum << ' ' << leavekid << endl;
    return 0;
}