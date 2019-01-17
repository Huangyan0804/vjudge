#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> ans;
int n, m;
void fun(int x) {
    if(ans.size() > m || ans.size() + n - x + 1 < m)
    return;
    if(x == n + 1){
        for(auto i: ans){
            cout << i << ' ';
        }
        cout << endl;
        return;
    }
    ans.push_back(x);
    fun(x + 1);
    ans.pop_back();
    fun(x + 1);
}
int main(){
    cin >> n >> m;
    fun(1);
    return 0;
}