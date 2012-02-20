/*
ID:   pinepar1
PROG: money
LANG: C++
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

#define FILEIO

#ifdef FILEIO
	FILE *in=fopen("money.in","r"),*out=fopen("money.out","w");
	#define scanf(...) fscanf(in,__VA_ARGS__)
	#define printf(...) fprintf(out,__VA_ARGS__)
#endif

const int COIN_NUM_MAX=25,MONEY_MAX=10000;
int coinNum,moneyAmount;
int coinValue[COIN_NUM_MAX];
long long wayNum[COIN_NUM_MAX+1][MONEY_MAX+1]={0};

int main(){
	scanf("%d%d",&coinNum,&moneyAmount);
	for(int coinIndex=0;coinIndex<coinNum;coinIndex++)
		scanf("%d",coinValue+coinIndex);
	for(int coin=0;coin<=coinNum;coin++)
		wayNum[coin][0]=1;
	for(int coin=1;coin<=coinNum;coin++)
		for(int money=1;money<=moneyAmount;money++){
			wayNum[coin][money]=wayNum[coin-1][money];
			if(money>=coinValue[coin-1])
				wayNum[coin][money]+=wayNum[coin][money-coinValue[coin-1]];
		}
	printf("%lld\n",wayNum[coinNum][moneyAmount]);
#ifdef FILEIO
	fclose(in);
	fclose(out);
#endif
	return 0;
}