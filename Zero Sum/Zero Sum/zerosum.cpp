/*
ID:   pinepar1
PROG: zerosum
LANG: C++
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

#define FILEIO

#ifdef FILEIO
	FILE *in=fopen("zerosum.in","r"),*out=fopen("zerosum.out","w");
	#define scanf(...) fscanf(in,__VA_ARGS__)
	#define printf(...) fprintf(out,__VA_ARGS__)
#endif

const char OPTION[4]=" +-";

void print(const char *intervals,const int digitNum){
	printf("1");
	for(int index=0;index<digitNum-1;index++)
		printf("%c%d",intervals[index],index+2);
	printf("\n");
}

int value(const char *intervals,const int digitNum){
	int result=0,sign=1;
	int temp=1;
	for(int index=0;index<digitNum-1;index++){
		if(intervals[index]==' ')
			temp=temp*10+index+2;
		else if(intervals[index]=='+'){
			result+=temp*sign;
			sign=1;
			temp=index+2;
		}
		else if(intervals[index]=='-'){
			result+=temp*sign;
			sign=-1;
			temp=index+2;
		}
	}
	result+=temp*sign;
	return result;
}

void fill(int index,char *intervals,const int digitNum){
	if(index==digitNum-1){
		if(value(intervals,digitNum)==0)
			print(intervals,digitNum);
		return;
	}
	for(int i=0;i<3;i++){
		intervals[index]=OPTION[i];
		fill(index+1,intervals,digitNum);
	}
}

int main(){
	int digitNum;
	scanf("%d",&digitNum);
	char *intervals=new char[digitNum];
	fill(0,intervals,digitNum);
	delete[] intervals;
#ifdef FILEIO
	fclose(in);
	fclose(out);
#endif
	return 0;
}