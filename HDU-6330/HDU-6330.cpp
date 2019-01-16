#include <algorithm>
#include<cstring>
#include <iostream>
using namespace std;
void printlen(int i){
    //for(int i = 0; i < )
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int x = a * 2 + 1; //横着
        int y = b * 2 + 1; //斜着
        int z = c * 2 + 1; //竖着
        int map[20][20];
        memset(map, ' ', sizeof(map));
        for(int i = 0; i < y; i ++){
            if(i % 2 == 0){

            }
        }
    }
    return 0;
}
// A 4 7 9 18 20
// B 2 10 11 13 19
// C 1 8 12 15 16 17
//D 3 5 6 14 