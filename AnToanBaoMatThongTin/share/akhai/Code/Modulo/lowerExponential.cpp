#include<bits/stdc++.h>
using namespace std;
// a ^ m mod n
int lowerExponential(int a, int m, int n){
	if(m == 1) return a % n;
	return int(pow(lowerExponential(a, m / 2, n), 2) * pow(a, m % 2)) % n;
}

int main(){
	int a, m, n;
	cout << "a ^ m mod n = ?" << endl;
	cout << "Nhap a, m, n: ";
	cin >> a >> m >> n;
	cout << a << "^" << m << " mod " << n << " = " << lowerExponential(a, m, n);
	return main();
}

