#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
/*
û��С���㣬���ü��㣬
��С���㣬��λ��������ҲҪ��0��
λ������ֱ���ƶ�С����
0.��ͷ�Ļ�Ҫȥ��ǰ����
��������ҲҪȥ
*/
int main() {
	string num;
	string allnum;
	string ans;
	int dots = 0;
	int eplus;
	cin >> num;
	eplus = stoi(num.substr(num.find('e') + 1));//e֮�������
	allnum = num.substr(0, num.find('e')); //e֮ǰ������

	if (allnum.find('.') != ans.npos)//�ж��Ƿ���С����
		dots = 1;
	if (dots == 0) {
		for (int i = 0; i < eplus; i++)
			ans.append("0");
	}
	else {
		string prenum, latternum;//�ָ�С����ǰ������
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