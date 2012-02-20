/*
ID: pinepar1
PROG: crypt1
LANG: C++
*/

#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>

FILE *in=fopen("crypt1.in","r"),*out=fopen("crypt1.out","w");

const int DIGIT_NUM_MAX=9;

int digitNum,digits[DIGIT_NUM_MAX],blank[5],count=0;

bool legal(int num){
	while(num!=0){
		int digit=num%10;
		bool found=false;
		for(int i=0;i<digitNum;i++)
			if(digits[i]==digit){
				found=true;
				break;
			}
		if(!found)
			return false;
		num/=10;
	}
	return true;
}

bool check(){
	int up=blank[0]*100+blank[1]*10+blank[2];
	int product1=up*blank[4],product2=up*blank[3];
	if(product1>999 || product2>999 || !legal(product1) || !legal(product2))
		return false;
	int product=product2*10+product1;
	return product<=9999 && legal(product);
}

void enumerate(int position){
	if(position>=5){
		if(check())
			count++;
		return;
	}
	for(int i=0;i<digitNum;i++){
		blank[position]=digits[i];
		enumerate(position+1);
	}
}

int main(){
	fscanf(in,"%d",&digitNum);
	for(int i=0;i<digitNum;i++)
		fscanf(in,"%d",digits+i);
	enumerate(0);
	fprintf(out,"%d\n",count);
	fclose(in);
	fclose(out);
	return 0;
}