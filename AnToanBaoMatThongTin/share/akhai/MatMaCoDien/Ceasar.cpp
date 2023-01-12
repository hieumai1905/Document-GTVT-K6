#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;
char sol(char a, int k){
	if(a > 'Z'){
		int p = a - 'a';
		int c = (p + k) % 26; // (p - k + 286) % 26
	 	return c + 'a';
	}else{
		int p = a - 'A';
		int c = (p + k) % 26;
		return c + 'A';
	}
	
}
string CeasarEncryption(string plaintext, int k){
	string cipher = "";
	for(auto i: plaintext){
		cipher += sol(i, k);
	}
	return cipher;
}
string CeasarDecryption(string plaintext, int k){
	string cipher = "";
	for(auto i: plaintext){
		cipher += sol(i, 26 - k);
	}
	return cipher;
}
int main()
{
	string plaintext;
	string cipher;
	int k;
	cout << "Input plaintext: ";
	cin >> plaintext;
	cout << "Input key:";
	cin >> k;	
	cipher = CeasarEncryption(plaintext, k);
	cout << cipher << endl;
	cout << CeasarDecryption(cipher, k);
}


