/*
ID:   pinepar1
PROG: sprime
LANG: C++
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

#define FILEIO

#ifdef FILEIO
	FILE *in=fopen("sprime.in","r"),*out=fopen("sprime.out","w");
	#define scanf(...) fscanf(in,__VA_ARGS__)
	#define printf(...) fprintf(out,__VA_ARGS__)
#endif

int length;
int digits[8];

void print(){
	for(int i=0;i<length;i++)
		printf("%d",digits[i]);
	printf("\n");
}

int value(int lastPosition){
	int result=0;
	for(int i=0;i<=lastPosition;i++)
		result=result*10+digits[i];
	return result;
}

bool isPrime(int num){
	if(num<2)
		return false;
	for(int i=2;i*i<=num;i++)
		if(num%i==0)
			return false;
	return true;
}

void fill(int position){
	if(position>=length){
		print();
		return;
	}
	for(digits[position]=0;digits[position]<=9;digits[position]++){
		int temp=value(position);
		if(isPrime(temp))
			fill(position+1);
	}
}

int main(){
	scanf("%d",&length);
	fill(0);
#ifdef FILEIO
	fclose(in);
	fclose(out);
#endif
	return 0;
}