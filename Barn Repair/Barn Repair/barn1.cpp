/*
ID: pinepar1
PROG: barn1
LANG: C++
*/

#include<iostream>

//#define DEBUG

#ifdef DEBUG
#define in std::cin
#define out std::cout

#else
#include<fstream>
std::ifstream fin("barn1.in",std::ios::in);
std::ofstream fout("barn1.out",std::ios::out);
#define in fin
#define out fout
#endif

#include<algorithm>
#include<functional>

const int BOARD_NUM_MAX=50,STALL_NUM_MAX=200;

int main(){
	int boardNum,stallNum,cowNum;
	in>>boardNum>>stallNum>>cowNum;
	bool stallOccupied[STALL_NUM_MAX];
	std::fill(stallOccupied,stallOccupied+stallNum,false);
	for(int i=0;i<cowNum;i++){
		int stallID;
		in>>stallID;
		stallOccupied[stallID-1]=true;
	}
	int firstOccupiedID,lastOccupiedID;
	for(firstOccupiedID=0;!stallOccupied[firstOccupiedID];firstOccupiedID++);
	for(lastOccupiedID=stallNum-1;!stallOccupied[lastOccupiedID];lastOccupiedID--);
	int stallBlockedNum=lastOccupiedID-firstOccupiedID+1;
	int gapLength[STALL_NUM_MAX/2],gapNum=0;
	bool inGap=false;
	for(int i=firstOccupiedID,length=0;i<=lastOccupiedID;i++){
		if(inGap){
			if(stallOccupied[i]){
				gapLength[gapNum++]=length;
				inGap=false;
			}
			else
				length++;
		}
		else if(!stallOccupied[i]){
			inGap=true;
			length=1;
		}
	}
	std::sort(gapLength,gapLength+gapNum,std::greater<int>());
	for(int i=0;i<boardNum-1 && i<gapNum;i++)
		stallBlockedNum-=gapLength[i];
	out<<stallBlockedNum<<std::endl;
	return 0;
}