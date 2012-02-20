/*
ID: pinepar1
PROG: gift1
LANG: C++
*/

#include<iostream>
#include<string>
#include<vector>
#include<map>

//#define DEBUG

#ifdef DEBUG
#define in std::cin
#define out std::cout

#else
#include<fstream>
std::ifstream fin("gift1.in",std::ios::in);
std::ofstream fout("gift1.out",std::ios::out);
#define in fin
#define out fout
#endif

int main(){
	int peopleNum;
	in>>peopleNum;
	std::vector<std::string> nameList;
	std::map<std::string,int> give,recieve;
	for(int i=0;i<peopleNum;i++){
		std::string name;
		in>>name;
		nameList.push_back(name);
		give[name]=0;
		recieve[name]=0;
	}
	for(int i=0;i<peopleNum;i++){
		std::string giver;
		int moneyTotal,recieverNum;
		in>>giver>>moneyTotal>>recieverNum;
		if(recieverNum==0)
			continue;
		moneyTotal-=moneyTotal%recieverNum;
		give[giver]=moneyTotal;
		for(int j=0;j<recieverNum;j++){
			std::string reciever;
			in>>reciever;
			recieve[reciever]+=moneyTotal/recieverNum;
		}
	}
	for(int i=0;i<peopleNum;i++){
		std::string name=nameList[i];
		out<<name<<" "<<recieve[name]-give[name]<<std::endl;
	}
	return 0;
}