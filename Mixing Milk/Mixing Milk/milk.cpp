/*
ID: pinepar1
PROG: milk
LANG: C++
*/

#include<iostream>

//#define DEBUG

#ifdef DEBUG
#define in std::cin
#define out std::cout

#else
#include<fstream>
std::ifstream fin("milk.in",std::ios::in);
std::ofstream fout("milk.out",std::ios::out);
#define in fin
#define out fout
#endif

#include<algorithm>

struct Farmer{
	int price,amount;
};

bool farmerCheaper(const Farmer &left,const Farmer &right){
	return left.price<right.price;
}

const int FARMER_NUM_MAX=5000;

int main(){
	int amountWanted,farmerNum;
	in>>amountWanted>>farmerNum;
	Farmer farmers[FARMER_NUM_MAX];
	for(int i=0;i<farmerNum;i++)
		in>>farmers[i].price>>farmers[i].amount;
	std::sort(farmers,farmers+farmerNum,farmerCheaper);
	int cost=0;
	for(int i=0;i<farmerNum && amountWanted>0;i++){
		int amountBuy=std::min(farmers[i].amount,amountWanted);
		cost+=amountBuy*farmers[i].price;
		amountWanted-=amountBuy;
	}
	out<<cost<<std::endl;
	return 0;
}