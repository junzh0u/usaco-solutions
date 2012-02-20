/*
ID: pinepar1
PROG: ride
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>

//#define DEBUG

std::ifstream fin("ride.in",std::ios::in);
std::ofstream fout("ride.out",std::ios::out);

#ifdef DEBUG
#define in std::cin
#define out std::cout
#else
#define in fin
#define out fout
#endif

int main(){
	std::string comet,group;
	in>>comet>>group;
	int cometNumber=1,groupNumber=1;
	for(unsigned i=0;i<comet.size();i++)
		cometNumber*=comet[i]-'A'+1;
	for(unsigned i=0;i<group.size();i++)
		groupNumber*=group[i]-'A'+1;
	if(cometNumber%47==groupNumber%47)
		out<<"GO"<<std::endl;
	else
		out<<"STAY"<<std::endl;
	return 0;
}