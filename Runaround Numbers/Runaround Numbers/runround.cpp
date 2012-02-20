/*
ID:   pinepar1
PROG: runround
LANG: C++
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>

#define FILEIO

#ifdef FILEIO
	FILE *in=fopen("runround.in","r"),*out=fopen("runround.out","w");
	#define scanf(...) fscanf(in,__VA_ARGS__)
	#define printf(...) fprintf(out,__VA_ARGS__)
#endif

//#define DEBUG

bool isRunaroundNumber(unsigned long number){
	int digitNum=0;
	int digits[10];
	bool digitAppear[10];
	std::fill(digitAppear,digitAppear+10,false);
	while(number){
		int digit=number%10;
		if(digit==0)
			return false;
		if(digitAppear[digit])
			return false;
		digits[digitNum++]=number%10;
		digitAppear[digit]=true;
		number/=10;
	}
	std::reverse(digits,digits+digitNum);
#ifdef DEBUG
	for(int i=0;i<digitNum;i++)
		printf("%d",digits[i]);
	printf("\n");
#endif
	bool digitVisited[10];
	std::fill(digitVisited,digitVisited+digitNum,false);
	int position=0;
	while(true){
		if(digitVisited[position])
			break;
		digitVisited[position]=true;
		position=(position+digits[position])%digitNum;
	}
	if(position!=0)
		return false;
	for(int i=0;i<digitNum;i++)
		if(!digitVisited[i])
			return false;
	return true;
}

int main(){
	unsigned long begin;
	scanf("%d",&begin);
	for(unsigned long number=begin+1;;number++)
		if(isRunaroundNumber(number)){
			printf("%u\n",number);
			break;
		}
#ifdef FILEIO
	fclose(in);
	fclose(out);
#endif
	return 0;
}