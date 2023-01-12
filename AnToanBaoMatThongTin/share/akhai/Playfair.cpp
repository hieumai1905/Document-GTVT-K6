#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string key = "monarchy";
int position(char a){
	if(a > 'Z'){
		return  a - 'a';
	 	
	}else{
		return a - 'A';
	}
}
string createMatrixKey(){
	string MatrixKey;
	int flag[26] = {};
	for(auto c: key){
		int p = position(c);
		if(!flag[p]){
			MatrixKey += c;
			flag[p] = 1;
		}
	}
	if(flag[position('j')]) flag[position('i')] = 1;
	else flag[position('j')] = 1;
	
	for(int i = 0; i < 26; i++){
		if(!flag[i]) MatrixKey += alphabet[i];
	}
	return MatrixKey;
}
string split(string input){
	string plaintext = "";
	int len = input.length();
	plaintext += input[0];
	int i = 1;
	while(i < len){
		if(input[i] == plaintext.back()){
			plaintext += "x";
		}else{
			plaintext += input[i];
			i++;
		}
	}
	if(plaintext.length() % 2) plaintext+= "x";
	return plaintext;
}
int main()
{
	cout << split("Ballon");
}


