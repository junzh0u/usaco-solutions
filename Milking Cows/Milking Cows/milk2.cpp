/*
ID: pinepar1
PROG: milk2
LANG: C++
*/

#include<iostream>

//#define DEBUG

#ifdef DEBUG
#define in std::cin
#define out std::cout

#else
#include<fstream>
std::ifstream fin("milk2.in",std::ios::in);
std::ofstream fout("milk2.out",std::ios::out);
#define in fin
#define out fout
#endif

#include<algorithm>

struct Interval{
	int begin,end;
};

bool farmerCompare(const Interval& left,const Interval& right){
	if(left.begin<right.begin)
		return true;
	if(left.begin>right.begin)
		return false;
	return left.end>right.end;
}

const int farmerNumMax=5000;
Interval intervals[farmerNumMax];
int farmerNum;

int main(){
	in>>farmerNum;
	for(int i=0;i<farmerNum;i++)
		in>>intervals[i].begin>>intervals[i].end;
	std::sort(intervals,intervals+farmerNum,farmerCompare);
	Interval prev=intervals[0];
	int longestIntervalLength=0,longestGapLength=0;
	for(int i=1;i<farmerNum;i++){
		if(intervals[i].begin>prev.end){
			if(longestIntervalLength<prev.end-prev.begin)
				longestIntervalLength=prev.end-prev.begin;
			if(longestGapLength<intervals[i].begin-prev.end)
				longestGapLength=intervals[i].begin-prev.end;
			prev=intervals[i];
		}
		else if(prev.end<intervals[i].end)
			prev.end=intervals[i].end;
	}
	if(longestIntervalLength<prev.end-prev.begin)
		longestIntervalLength=prev.end-prev.begin;
	out<<longestIntervalLength<<" "<<longestGapLength<<std::endl;
	return 0;
}