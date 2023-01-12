#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string cipher =   "dilovfheakgtbyzsmwnurxpqcj";
int position(char a){
	if(a > 'Z'){
		return  a - 'a';
	 	
	}else{
		return a - 'A';
	}
}
string monialphabetEncyption(string input){
	string ciphertext = "";
	for(auto i: input){
		int p = position(i);
		ciphertext += cipher[p];
	}
	return ciphertext;
}
int *inverseKey(){
	int *index = new int[26];
	for(int i = 0; i < 26; i++){
		index[position(cipher[i])] = i;
	}
	return index;
}
string monialphabetDecyption(string input){
	int *index = inverseKey();
	string plaintext = "";
	for(auto i: input){
		int p = position(i);
		plaintext += alphabet[index[p]];
	}
	return plaintext;
}
int main()
{
	string plaintext = "HiCanyouknowthisMessage";
	cout << "Plaintext: " << plaintext << endl;
	string text = monialphabetEncyption(plaintext);
	cout << "Ciphertext: " << text << endl;
	cout << "Decryption:" << monialphabetDecyption(text);
}


