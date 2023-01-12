#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int position(char a){
	if(a > 'Z'){
		return  a - 'a';
	 	
	}else{
		return a - 'A';
	}
}
int K[3][3] = {{17,17,5},{21,18,21},{2,2,19}};
int m = 3;
//int K1[3][3] = {{4,9,15},{15,17,6},{24,0,17}};
string HillCipher(string blockm){
	string cipher;
	
	int P[m], C[m];
	for(int i = 0; i < m; i++){
		P[i] = position(blockm[i]);
	}

	for(int j = 0; j < m; j++){
		C[j] = 0;
		for(int i = 0; i < m; i++){
			C[j] += P[i] * K[i][j];
		}
		cipher += alphabet[C[j] % 26];
	}
	return cipher;
}
string HillEncryption(string input){
	string plaintext = input;
	int pad = input.length() % m;
	if(pad){
		for(int i = pad + 1; i <= m; i++){
			plaintext += 'X';
		}
	}
	cout << "Plaintext after add pad: " << plaintext << " " << plaintext.length();
	string ciphertext = "";
	for(int i = 0; i < plaintext.length(); i+=m){
		
		char buff[m+2];
		
		size_t length = plaintext.copy(buff, m, i);
		
		buff[length] = '\0';
		ciphertext += HillCipher(buff);
		
		
	}
//	cout << "\ncheck" << ciphertext << endl;
	return ciphertext;
}
int main()
{
	freopen("input.txt", "r", stdin);
	string input;
	cin >> input;
	cout<<"Input: " << input << endl;
	cout<<"\nHill Encyption: "<< HillEncryption(input) <<"\n";	
}


