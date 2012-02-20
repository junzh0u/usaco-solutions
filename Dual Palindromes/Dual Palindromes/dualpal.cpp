/*
ID: pinepar1
PROG: dualpal
LANG: C++
*/

#include<iostream>

//#define DEBUG

#ifdef DEBUG
#define in std::cin
#define out std::cout

#else
#include<fstream>
std::ifstream fin("dualpal.in",std::ios::in);
std::ofstream fout("dualpal.out",std::ios::out);
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

void numberToDigitsInBase(int number,int base,char digits[]){
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
	int n,start;
	in>>n>>start;
	for(int number=start+1,count=0;count<n;number++){
		char digits[40];
		int palindromicBaseNum=0;
		for(int base=2;base<=10;base++){
			numberToDigitsInBase(number,base,digits);
			if(isPalindromic(digits))
				palindromicBaseNum++;
		}
		if(palindromicBaseNum>=2){
			out<<number<<std::endl;
			count++;
		}
	}
	return 0;
}