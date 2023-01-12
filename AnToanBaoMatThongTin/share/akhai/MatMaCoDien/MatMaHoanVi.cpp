#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;
string PermutationEncyption(string input, int key){
	string output="";
	int i = 0 , j = 0, len_out = 0, len_in = input.length();
	while(i<key){ 
		j = i; 
		while(j < len_in){
			output += input[j];
			j+=key;
		}
		i++;
	}
	return output;
}
string PermutationDecyption(string input, int key){
	string output="";
	int i = 0 , j = 0, len_out = 0, len_in = input.length();
	int col = len_in/key;
	if(len_in%key) col++;
	while(i<col){
		j = i; 
		while(j < len_in){
			output += input[j];
			j+=col;
		}
		i++;
	}
	return output;
}
int main()
{
	string input;
	int key;
	input = "wearediscoveredsaveyourself";
	key = 4;
	cout<<"Input: " << input << endl;
	cout<<"Key: " << key << endl;
	
	input = PermutationEncyption(input, key);
	cout<<"\nPermutation Encyption: "<<input<<endl;
	cout<<"Permutation Decyption: "<<PermutationDecyption(input, key);
}


