/*
ID:		pinepar1
PROG:	friday
LANG:	C++
*/

#include<iostream>

//#define DEBUG

#ifdef DEBUG
#define in std::cin
#define out std::cout

#else
#include<fstream>
std::ifstream fin("friday.in",std::ios::in);
std::ofstream fout("friday.out",std::ios::out);
#define in fin
#define out fout
#endif

bool isLeap(int year){
	if(year%4!=0)
		return false;
	if(year%100==0)
		return year%400==0;
	return true;
}

int dayNumOfMonth(int year,int month){
	const static int DAY_NUM_OF_MONTH[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(month==2 && isLeap(year))
		return DAY_NUM_OF_MONTH[month-1]+1;
	return DAY_NUM_OF_MONTH[month-1];
}

int main(){
	int yearNum;
	in>>yearNum;
	int count[7]={0},fall=0;
	for(int year=1900;year<1900+yearNum;year++)
		for(int month=1;month<=12;month++){
			count[fall]++;
			fall=(fall+dayNumOfMonth(year,month))%7;
		}
	for(int i=0;i<7;i++){
		out<<count[i];
		if(i!=6)
			out<<" ";
	}
	out<<std::endl;
	return 0;
}