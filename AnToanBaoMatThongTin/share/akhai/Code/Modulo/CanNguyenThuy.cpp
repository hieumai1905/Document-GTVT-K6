#include<bits/stdc++.h>

using namespace std;

int calPhi(int n){
	int res = 0;
	for(int i = 0; i < n; i++)
		if(__gcd(n, i) == 1)
			res++;
	return res;
}

int main(){
	int a, n;
	cout << "Nhap a, n: ";
	cin >> a >> n;
	
	if(__gcd(n, a) == 1){
		int phi_n = calPhi(n);
		bool flag = false;
		if(int(pow(a, phi_n)) % n  == 1) 
			flag = true;
		
		for(int i = 1; i < phi_n; i++){
			if(int(pow(a, i)) % n == 1){
				flag = false;
				break;
			}
		}		
		if(flag == true) 
			cout << a << " la can nguyen thuy cua " << n;
		else 
			cout << a << " khong la can nguyen thuy cua " <<n;
	}
	else 
		cout << a << " khong la can nguyen thuy cua " << n;
}

