#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
	double a, b, c, i, n, delta;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a >> b >> c;
		delta = b * b - 4 * a*c;
		cout << fixed << setprecision(5);
		if (fabs(delta) < 1e-8){
			cout << "x1=x2=" << -b / a / 2 << endl;
		}
		else if (delta > 0){
			cout << "x1=" << (-b + sqrt(delta)) / 2 / a << ";" << "x2=" << (-b - sqrt(delta)) / 2 / a << endl;
		}
		else if (delta < 0){
			delta = 0 - delta;
			double tmp = -b / a / 2;
			if (fabs(tmp) < 1e-8) tmp = 0.0;
			cout << "x1=" << tmp << "+" << sqrt(delta) / 2 / a << "i;x2=" << tmp << -sqrt(delta) / 2 / a << "i" << endl;
		}
	}
	return 0;
}