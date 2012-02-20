/*
ID:   pinepar1
PROG: numtri
LANG: C++
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>

#define FILEIO

#ifdef FILEIO
	FILE *in=fopen("numtri.in","r"),*out=fopen("numtri.out","w");
	#define scanf(...) fscanf(in,__VA_ARGS__)
	#define printf(...) fprintf(out,__VA_ARGS__)
#endif

const int SIZE_LIMIT=1000;
int matrix[SIZE_LIMIT][SIZE_LIMIT];

int main(){
	int size;
	scanf("%d",&size);
	for(int row=0;row<size;row++)
		for(int col=0;col<=row;col++)
			scanf("%d",&matrix[row][col]);
	for(int row=size-2;row>=0;row--)
		for(int col=0;col<=row;col++)
			matrix[row][col]+=std::max(matrix[row+1][col],matrix[row+1][col+1]);
	printf("%d\n",matrix[0][0]);
#ifdef FILEIO
	fclose(in);
	fclose(out);
#endif
	return 0;
}