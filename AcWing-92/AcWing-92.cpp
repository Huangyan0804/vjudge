#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> ans;
int n;
void fun(int i){
    if(i == n + 1){
        for(auto x: ans){
            cout << x << ' ';
        }
        cout << endl;
        return;
    }
    fun(i + 1);
    ans.push_back(i);
    fun(i + 1);
    ans.pop_back();
}
int main(){
    cin >> n;
    fun(1);
    return 0;
}