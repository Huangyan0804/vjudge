#include <algorithm>
#include <iostream>
#include<map>
using namespace std;
const int N = 200005;
int a[N], b[N];
int main()
{
    int n, m;
    map<int, int> mp;
    cin >> n;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        mp[num]++;
    }
    cin >> m;
    for(int i = 0 ; i< m; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int maxa = 0;
    int temp = 1;
    int maxb = 0;
    for (int i = 0; i < m; i++) {
        if(mp[a[i]] > maxa){
            maxa = mp[a[i]];
            temp = i + 1;
            maxb = mp[b[i]];
        }else if(mp[a[i]] == maxa){
            if(maxb < mp[b[i]]){
                temp = i + 1;
                maxb = mp[b[i]];
            }
        }
    }
    cout << temp << endl;
    return 0;
}