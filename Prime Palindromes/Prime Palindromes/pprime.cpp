/*
ID:   pinepar1
PROG: pprime
LANG: C++
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#include<cstdlib>

#define FILEIO

#ifdef FILEIO
	FILE *in=fopen("pprime.in","r"),*out=fopen("pprime.out","w");
	#define scanf(...) fscanf(in,__VA_ARGS__)
	#define printf(...) fprintf(out,__VA_ARGS__)
#endif

int lower,upper;
int list[100000];
int listSize;

int digitNum(int integer){
	int num=0;
	while(integer>0){
		integer/=10;
		num++;
	}
	return num;
}

bool isPrime(int num){
	for(int i=2;i*i<=num;i++)
		if(num%i==0)
			return false;
	return true;
}

void generatePalindrome(char digits[],int first,int last){
	if(first>last){
		int value=atoi(digits);
		if(value>=lower && value<=upper && isPrime(value))
			list[listSize++]=value;
		return;
	}
	for(int i=0;i<=9;i++){
		digits[first]=digits[last]='0'+i;
		generatePalindrome(digits,first+1,last-1);
	}
}

void testPalindrome(int length){
	char digits[10];
	digits[length]='\0';
	generatePalindrome(digits,0,length-1);
}

int main(){
	scanf("%d%d",&lower,&upper);
	listSize=0;
	for(int length=digitNum(lower);length<=digitNum(upper);length++)
		testPalindrome(length);
	std::sort(list,list+listSize);
	for(int i=0;i<listSize;i++)
		printf("%d\n",list[i]);
#ifdef FILEIO
	fclose(in);
	fclose(out);
#endif
	return 0;
}