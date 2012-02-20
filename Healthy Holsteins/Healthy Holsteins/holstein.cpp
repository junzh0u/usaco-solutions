/*
ID:   pinepar1
PROG: holstein
LANG: C++
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#include<climits>

#define FILEIO

#ifdef FILEIO
	FILE *in=fopen("holstein.in","r"),*out=fopen("holstein.out","w");
	#define scanf(...) fscanf(in,__VA_ARGS__)
	#define printf(...) fprintf(out,__VA_ARGS__)
#endif

const int VITA_TYPE_NUM_MAX=25;
int vitaminTypeNum;
int vitaminRequirement[VITA_TYPE_NUM_MAX];

const int FEED_TYPE_NUM_MAX=15;
int feedTypeNum;
int vitaminInFeed[FEED_TYPE_NUM_MAX][VITA_TYPE_NUM_MAX];

int bestFeedTypeNum;
int bestFeedTypeList[FEED_TYPE_NUM_MAX];

int eatenFeedTypeNum;
int eatenFeedTypeList[FEED_TYPE_NUM_MAX];
int vitaminEaten[VITA_TYPE_NUM_MAX];

bool requirementMeet(){
	for(int v=0;v<vitaminTypeNum;v++)
		if(vitaminEaten[v]<vitaminRequirement[v])
			return false;
	return true;
}

void feed(int feedType){
	if(bestFeedTypeNum<=eatenFeedTypeNum)
		return;
	if(requirementMeet()){
		bestFeedTypeNum=eatenFeedTypeNum;
		std::copy(eatenFeedTypeList,eatenFeedTypeList+eatenFeedTypeNum,bestFeedTypeList);
		return;
	}
	if(feedType>=feedTypeNum)
		return;

	for(int v=0;v<vitaminTypeNum;v++)
		vitaminEaten[v]+=vitaminInFeed[feedType][v];
	eatenFeedTypeList[eatenFeedTypeNum++]=feedType;
	feed(feedType+1);

	for(int v=0;v<vitaminTypeNum;v++)
		vitaminEaten[v]-=vitaminInFeed[feedType][v];
	eatenFeedTypeNum--;
	feed(feedType+1);
}

int main(){
	scanf("%d",&vitaminTypeNum);
	for(int v=0;v<vitaminTypeNum;v++)
		scanf("%d",vitaminRequirement+v);
	scanf("%d",&feedTypeNum);
	for(int f=0;f<feedTypeNum;f++)
		for(int v=0;v<vitaminTypeNum;v++)
			scanf("%d",&vitaminInFeed[f][v]);
	bestFeedTypeNum=INT_MAX;
	eatenFeedTypeNum=0;
	std::fill(vitaminEaten,vitaminEaten+vitaminTypeNum,0);
	feed(0);
	printf("%d",bestFeedTypeNum);
	for(int f=0;f<bestFeedTypeNum;f++)
		printf(" %d",bestFeedTypeList[f]+1);
	printf("\n");
#ifdef FILEIO
	fclose(in);
	fclose(out);
#endif
	return 0;
}