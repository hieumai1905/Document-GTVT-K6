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
	int n;
	cin >> n;
	cout << "O(" << n << ") = " << calPhi(n);


return 0;
}

