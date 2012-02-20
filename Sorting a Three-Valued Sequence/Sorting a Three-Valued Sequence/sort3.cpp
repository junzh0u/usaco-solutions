/*
ID:   pinepar1
PROG: sort3
LANG: C++
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>

#define FILEIO

#ifdef FILEIO
	FILE *in=fopen("sort3.in","r"),*out=fopen("sort3.out","w");
	#define scanf(...) fscanf(in,__VA_ARGS__)
	#define printf(...) fprintf(out,__VA_ARGS__)
#endif

const int LEN_MAX=1000;
int sequence[LEN_MAX];
int length;
int count[3];
int matrix[3][3];
int swapCount;

void swap2(int left,int right){
	int count=std::min(matrix[left][right],matrix[right][left]);
	matrix[left][right]-=count;
	matrix[right][left]-=count;
	swapCount+=count;
}

void swap3(){
	int count=matrix[0][1]+matrix[0][2];
	swapCount+=count*2;
}

int main(){
	scanf("%d",&length);
	for(int i=0;i<3;i++)
		count[i]=0;
	for(int i=0;i<length;i++){
		scanf("%d",sequence+i);
		sequence[i]--;
		count[sequence[i]]++;
	}
	for(int suposed=0;suposed<3;suposed++){
		for(int actual=0;actual<3;actual++)
			matrix[suposed][actual]=0;
		int begin=0;
		for(int i=0;i<suposed;i++)
			begin+=count[i];
		int end=begin+count[suposed];
		for(int i=begin;i<end;i++)
			matrix[suposed][sequence[i]]++;
	}
	swapCount=0;
	swap2(0,1);
	swap2(1,2);
	swap2(2,0);
	swap3();
	printf("%d\n",swapCount);
#ifdef FILEIO
	fclose(in);
	fclose(out);
#endif
	return 0;
}