#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
/*
没有小数点，后置加零，
有小数点，但位数不够，也要加0，
位数够，直接移动小数点
0.开头的话要去除前导零
如果后导零多也要去
*/
int main() {
	string num;
	string allnum;
	string ans;
	int dots = 0;
	int eplus;
	cin >> num;
	eplus = stoi(num.substr(num.find('e') + 1));//e之后的数字
	allnum = num.substr(0, num.find('e')); //e之前的数字

	if (allnum.find('.') != ans.npos)//判断是否有小数点
		dots = 1;
	if (dots == 0) {
		for (int i = 0; i < eplus; i++)
			ans.append("0");
	}
	else {
		string prenum, latternum;//分割小数点前后数字
		prenum = allnum.substr(0, allnum.find('.'));
		latternum = allnum.substr(allnum.find('.') + 1);

		if (latternum.length() < eplus) {
			if (prenum == "0") {
				ans = latternum;
			}
			else
				ans = prenum + latternum;
			for (int i = 0; i < eplus - latternum.length(); i++)
				ans.append("0");
		}
		else if (latternum.length() == eplus) {
			if (prenum == "0") {
				ans = latternum;
			}
			else
				ans = prenum + latternum;
		}
		else {
			latternum.insert(eplus, ".");
				ans = prenum + latternum;
		}
	}
	if (ans.find('.') != ans.npos) {
		string::iterator iter = ans.end();
		--iter;
		while (*iter !='.' ) {
			if (*iter == '0') {
				ans.erase(iter);
			}
			else
				break;
			--iter;
		}
		if (*iter == '.')
			ans.erase(iter);
	}
	cout << ans;
	//system("pause");
	return 0;
}