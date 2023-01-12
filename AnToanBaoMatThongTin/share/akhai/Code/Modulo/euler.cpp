#include<bits/stdc++.h>
using namespace std;
// a^m mod n
int lowerExponential(int a, int m, int n){
	if(m == 1) return a % n;
	return int(pow(lowerExponential(a, m / 2, n), 2) * pow(a, m % 2)) % n;
}
bool checkPrime(int n){
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i)
			return false;
	}
	return true;
}
int calPhi(int n){
	int res = 0;
	for(int i = 0; i < n; i++)
		if(__gcd(n, i) == 1)
			res++;
	return res;
}

int main(){
	int a, m, n;
	cout << "a ^ m mod n = ?" << endl;
	cout << "Nhap a, m, n: ";
	cin >> a >> m >> n;
	
	int phiN = calPhi(n);
	
	if(!checkPrime(n)){
		int _m = m;
		if(__gcd(a,n) == 1){
			while(_m > n)
				_m = _m - phiN;
			cout << a << "^" << m << " mod " << n << " = " << lowerExponential(a, _m, n);
			
		}
		else{
			while(_m > n)
				_m = _m - (phiN + 1);
			cout << a << "^" << m << " mod " << n << " = " << lowerExponential(a, _m, n);
			
		}
	}
	else
		cout << a << "^" << m << " mod " << n << " = " << lowerExponential(a, m, n);

return 0;
}

