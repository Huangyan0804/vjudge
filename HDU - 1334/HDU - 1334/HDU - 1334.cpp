#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main() {
	for (int i = 6; i <= 200; i++) {
		int a = i * i*i;
		for (int j = 2; j <= i; j++) {
			int b = j * j*j;
			for (int k = j ; k <= i; k++) {
				int c = k * k*k;
				if (a < b + c)
					break;
				for (int l = k ; l <= i; l++) {
					int d = l * l*l;
					if (a < b + c + d)
						break;
					if (a==b+c+d) {
						printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, k, l);
					}
				}
			}
		}
	}
	return 0;
}