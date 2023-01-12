#include<bits/stdc++.h>
using namespace std;

//a^-1 mod n

int main(){
	int a, n;
	cout << "a ^ -1 mod n = ?" << endl;
	cout << "Nhap a, n: ";
	cin >> a >> n;
	
	cout << a << "^-1 mod " << n << endl;
	int q, a1, a2, a3, b1, b2, b3;
	a1 = 1 , a2 = 0 , a3 = n , b1 = 0 , b2 = 1 , b3 = a;
	while(b3 != 0 && b3 != 1){
		q = a3 / b3;
		
		int b1_cp = b1, b2_cp = b2, b3_cp = b3;
		
		b1 = a1 - b1 * q;
		b2 = a2 - b2 * q;
		b3 = a3 - b3 * q;
		a1 = b1_cp;
		a2 = b2_cp;
		a3 = b3_cp;
	}
	if(b3 == 1){
		cout << "\nSo nghich dao cua " << a << " la : " << b2 << endl;
		cout << "Ket qua a^-1 mod n = " << (b2 + n) % n;
	}
	else 
		cout << "\nKhong tim thay so nghich dao";
}

