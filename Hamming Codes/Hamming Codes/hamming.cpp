/*
ID:   pinepar1
PROG: hamming
LANG: C++
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

#define FILEIO

#ifdef FILEIO
	FILE *in=fopen("hamming.in","r"),*out=fopen("hamming.out","w");
	#define scanf(...) fscanf(in,__VA_ARGS__)
	#define printf(...) fprintf(out,__VA_ARGS__)
#endif

const int WORD_NUM_MAX=64;
int wordNum,wordLen,distanceMin;
int words[WORD_NUM_MAX];

int main(){
	scanf("%d%d%d",&wordNum,&wordLen,&distanceMin);
	words[0]=0;
	for(int cur=1;cur<wordNum;cur++){
		for(int word=words[cur-1]+1;word<(1<<wordLen);word++){
			bool satisfied=true;
			for(int prev=0;prev<cur;prev++){
				int difference=word^words[prev];
				int distance=0;
				while(difference){
					if(difference&1)
						distance++;
					difference>>=1;
				}
				if(distance<distanceMin){
					satisfied=false;
					break;
				}
			}
			if(satisfied){
				words[cur]=word;
				break;
			}
		}
	}
	for(int i=0;i<wordNum;i++){
		printf("%d",words[i]);
		if(i%10==9 || i==wordNum-1)
			printf("\n");
		else
			printf(" ");
	}
#ifdef FILEIO
	fclose(in);
	fclose(out);
#endif
	return 0;
}