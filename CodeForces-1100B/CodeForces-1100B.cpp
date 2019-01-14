#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int num;
    set<int> st;
    map<int, int> mp;
    for (int i = 0; i < m; i++) {
        cin >> num;
        mp[num]++;
        st.insert(num);
        if (st.size() == n) {
            for (int x = 1; x <= n; x++) {
                mp[x]--;
                if (mp[x] == 0) {
                    st.erase(x);
                }
            }
            printf("1");
        } else {
            printf("0");
        }
    }
    return 0;
}