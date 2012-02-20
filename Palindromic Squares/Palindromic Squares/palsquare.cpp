/*
ID: pinepar1
PROG: palsquare
LANG: C++
*/

#include<iostream>

//#define DEBUG

#ifdef DEBUG
#define in std::cin
#define out std::cout

#else
#include<fstream>
std::ifstream fin("palsquare.in",std::ios::in);
std::ofstream fout("palsquare.out",std::ios::out);
#define in fin
#define out fout
#endif

#include<algorithm>
#include<cstring>

char digitToChar(int digit){
	if(digit<10)
		return '0'+digit;
	return 'A'+digit-10;
}

void numberToStringInBase(int number,int base,char digits[]){
	int digitNum=0;
	while(number>0){
		digits[digitNum++]=digitToChar(number%base);
		number/=base;
	}
	std::reverse(digits,digits+digitNum);
	digits[digitNum]='\0';
}

bool isPalindromic(char digits[]){
	int digitNum=strlen(digits);
	for(int i=0;i<digitNum-1-i;i++)
		if(digits[i]!=digits[digitNum-1-i])
			return false;
	return true;
}

int main(){
	int base;
	in>>base;
	for(int n=1;n<=300;n++){
		char square[20];
		numberToStringInBase(n*n,base,square);
		if(isPalindromic(square)){
			char number[20];
			numberToStringInBase(n,base,number);
			out<<number<<" "<<square<<std::endl;
		}
	}
	return 0;
}