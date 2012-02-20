/*
ID:   pinepar1
PROG: preface
LANG: C++
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<algorithm>

#define FILEIO

#ifdef FILEIO
	FILE *in=fopen("preface.in","r"),*out=fopen("preface.out","w");
	#define scanf(...) fscanf(in,__VA_ARGS__)
	#define printf(...) fprintf(out,__VA_ARGS__)
#endif

const int ROMAN_LEN_MAX=20;

void arabicToRoman(int arabic,char roman[]){
	roman[0]='\0';
	while(arabic>=1000){
		strcat(roman,"M");
		arabic-=1000;
	}
	if(arabic>=900){
		strcat(roman,"CM");
		arabic-=900;
	}
	if(arabic>=500){
		strcat(roman,"D");
		arabic-=500;
	}
	if(arabic>=400){
		strcat(roman,"CD");
		arabic-=400;
	}
	while(arabic>=100){
		strcat(roman,"C");
		arabic-=100;
	}
	if(arabic>=90){
		strcat(roman,"XC");
		arabic-=90;
	}
	if(arabic>=50){
		strcat(roman,"L");
		arabic-=50;
	}
	if(arabic>=40){
		strcat(roman,"XL");
		arabic-=40;
	}
	while(arabic>=10){
		strcat(roman,"X");
		arabic-=10;
	}
	if(arabic>=9){
		strcat(roman,"IX");
		arabic-=9;
	}
	if(arabic>=5){
		strcat(roman,"V");
		arabic-=5;
	}
	if(arabic>=4){
		strcat(roman,"IV");
		arabic-=4;
	}
	while(arabic>=1){
		strcat(roman,"I");
		arabic-=1;
	}
}

const char ROMAN_LETTER[8]="IVXLCDM";

int count[7];

void accumulate(char roman[]){
	for(int i=0;roman[i]!='\0';i++){
		switch(roman[i]){
			case 'I':
				count[0]++;
				break;
			case 'V':
				count[1]++;
				break;
			case 'X':
				count[2]++;
				break;
			case 'L':
				count[3]++;
				break;
			case 'C':
				count[4]++;
				break;
			case 'D':
				count[5]++;
				break;
			case 'M':
				count[6]++;
				break;
			default:
				break;
		}
	}
}

int main(){
	std::fill(count,count+7,0);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char roman[ROMAN_LEN_MAX];
		arabicToRoman(i,roman);
		accumulate(roman);
	}
	for(int i=0;i<7;i++)
		if(count[i])
			printf("%c %d\n",ROMAN_LETTER[i],count[i]);
#ifdef FILEIO
	fclose(in);
	fclose(out);
#endif
	return 0;
}