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
string createMatrixKey(string key){
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
	int i = 0;
	while(i < len){
		if(input[i] == input[i + 1]){
			plaintext += input[i];
			plaintext += "X";
			i++;
		}else{
			plaintext += input[i];
			if(i + 1 < len) plaintext += input[i + 1];
			i+=2;
		}
	}
	if(plaintext.length() % 2) plaintext+= "X";
	return plaintext;
}
int *createIndex(string matrixKey){
	int *index = new int[26];
	for(int i = 0; i < 25; i++){
		int pos = position(matrixKey[i]);
		index[pos] = i;
	}
	index[position('j')] = index[position('i')];
	return index;
}
string PlayFairEncyption(string input, string key){
	string plaintext = split(input);
	cout << "Plaintext after Split: " << plaintext << " " << plaintext.length() << endl;
	string matrixKey = createMatrixKey(key);
	int *index = createIndex(matrixKey);
	string ciphertext = "";
	for(int i = 0; i < input.length(); i+=2){
		int p1 = index[position(plaintext[i])];
		int p2 = index[position(plaintext[i + 1])];
		int row1 = p1 / 5, col1 = p1 % 5;
		int row2 = p2 / 5, col2 = p2 % 5;
		int c1, c2;
		if(row1 == row2){
			col1 = (col1 + 1) % 5;
			col2 = (col2 + 1) % 5;
			c1 = row1 * 5 + col1;
			c2 = row2 * 5 + col2;
		}
		else if(col1 == col2){
			row1 = (row1 + 5) % 5;
			row2 = (row2 + 5) % 5;
			c1 = row1 * 5 + col1;
			c2 = row2 * 5 + col2;
		}
		else{
			c1 = row1 * 5 + col2;
			c2 = row2 * 5 + col1;
		}
		ciphertext+=matrixKey[c1];
		ciphertext+=matrixKey[c2];
	}
	return ciphertext;
}
int main()
{
	string input = "HELLOONEANDALL";
	string key = "MONARCHY";
	cout<<"Input: " << input << endl;
	cout<<"Key: " << key << endl;

	input = PlayFairEncyption(input,key);
	cout<<"\nPlayFair Encyption: "<<input<<"\n";
}


