/*
ID:   pinepar1
PROG: nocows
LANG: C++
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

#define FILEIO

#ifdef FILEIO
	FILE *in=fopen("nocows.in","r"),*out=fopen("nocows.out","w");
	#define scanf(...) fscanf(in,__VA_ARGS__)
	#define printf(...) fprintf(out,__VA_ARGS__)
#endif

const int SIZE_MAX=200,HEIGHT_MAX=100;

int maxSize(int height){
	return (1<<height)-1;
}

int minSize(int height){
	return 2*height-1;
}

int maxHeight(int size){
	return (size+1)/2;
}

int minHeight(int size){
	for(int height=0;;height++)
		if(maxSize(height)>=size)
			return height;
}

int shorterTreeNum[SIZE_MAX+1][HEIGHT_MAX+1]={0};

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int height=1;height<=k;height++)
		shorterTreeNum[1][height]=1;
	for(int size=3;size<=n;size+=2){
		for(int height=1;height<=k;height++){
			for(int leftSize=1;leftSize<=size-2;leftSize+=2){
				int rightSize=size-1-leftSize;
				shorterTreeNum[size][height]+=shorterTreeNum[leftSize][height-1]*shorterTreeNum[rightSize][height-1];
				shorterTreeNum[size][height]%=9901;
			}
		}
	}
	printf("%d\n",(shorterTreeNum[n][k]-shorterTreeNum[n][k-1]+9901)%9901);
#ifdef FILEIO
	fclose(in);
	fclose(out);
#endif
	return 0;
}