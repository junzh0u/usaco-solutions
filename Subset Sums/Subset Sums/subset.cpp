/*
ID:   pinepar1
PROG: subset
LANG: C++
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

//#define FILEIO

#ifdef FILEIO
	FILE *in=fopen("subset.in","r"),*out=fopen("subset.out","w");
	#define scanf(...) fscanf(in,__VA_ARGS__)
	#define printf(...) fprintf(out,__VA_ARGS__)
#endif

const int N_MAX=39;
long long unsigned memory[N_MAX+1][N_MAX*(N_MAX)/4+1];
int n;

long long unsigned setNum(int begin,int sum){
	if(sum==0)
		return 1;
	if(begin>n)
		return 0;
	if(memory[begin][sum]==-1)
		memory[begin][sum]=setNum(begin+1,sum-begin)+setNum(begin+1,sum);
	return memory[begin][sum];
}

int main(){
	FILE *in=fopen("subset.in","r");
	fscanf(in,"%d",&n);
	fclose(in);
	if(n*(n+1)%4)
		printf("0\n");
	else{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n*(n+1)/4;j++)
				memory[i][j]=-1;
		FILE *out=fopen("subset.out","w");
		fprintf(out,"%llu\n",setNum(1,n*(n+1)/4)/2);
		fclose(out);
	}
#ifdef FILEIO
	fclose(in);
	fclose(out);
#endif
	return 0;
}