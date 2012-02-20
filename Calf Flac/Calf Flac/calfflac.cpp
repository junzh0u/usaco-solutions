/*
ID: pinepar1
PROG: calfflac
LANG: C++
*/

#include<iostream>

//#define DEBUG

#ifdef DEBUG
#define in std::cin
#define out std::cout

#else
#include<fstream>
std::ifstream fin("calfflac.in",std::ios::in);
std::ofstream fout("calfflac.out",std::ios::out);
#define in fin
#define out fout
#endif

const int STRING_LEN_MAX=20000;
char string[STRING_LEN_MAX+1];

int left(int index){
	do{
		index--;
	}while(index>0 && !isalpha(string[index]));
	return index;
}

int right(int index){
	do{
		index++;
	}while(string[index]!='\0' && !isalpha(string[index]));
	return index;
}

int main(){
	int stringLen=0;
	while(true){
		char character=in.get();
		if(character==EOF)
			break;
		string[stringLen++]=character;
	}
	string[stringLen]='\0';
	int longestPalindromeLength=0,longestPalindromeLeft=0,longestPalindromeRight=stringLen-1;
	for(int i=0;i<stringLen;i=right(i)){
		if(isalpha(string[i])){
			int palindromeMid=i,palindromeLeft=left(i),palindromeRight=right(i),palindromeLength=1;
			while(	palindromeLeft>=0 && palindromeRight<stringLen &&
					tolower(string[palindromeLeft])==tolower(string[palindromeRight])){
				palindromeLength+=2;
				palindromeLeft=left(palindromeLeft);
				palindromeRight=right(palindromeRight);
			}
			if(longestPalindromeLength<palindromeLength){
				longestPalindromeLength=palindromeLength;
				longestPalindromeLeft=right(palindromeLeft);
				longestPalindromeRight=left(palindromeRight);
			}
			palindromeLeft=i;
			palindromeRight=right(i);
			palindromeLength=0;
			while(	palindromeLeft>=0 && palindromeRight<stringLen &&
					tolower(string[palindromeLeft])==tolower(string[palindromeRight])){
				palindromeLength+=2;
				palindromeLeft=left(palindromeLeft);
				palindromeRight=right(palindromeRight);
			}
			if(longestPalindromeLength<palindromeLength){
				longestPalindromeLength=palindromeLength;
				longestPalindromeLeft=right(palindromeLeft);
				longestPalindromeRight=left(palindromeRight);
			}
		}
	}
	out<<longestPalindromeLength<<std::endl;
	for(int i=longestPalindromeLeft;i<=longestPalindromeRight;i++)
		out.put(string[i]);
	out.put('\n');
	return 0;
}