/*
ID: pinepar1
PROG: namenum
LANG: C++
*/

#include<iostream>

//#define DEBUG

#ifdef DEBUG
#define in std::cin
#define out std::cout
#define dict std::cin

#else
#include<fstream>
std::ifstream fin("namenum.in",std::ios::in);
std::ofstream fout("namenum.out",std::ios::out);
std::ifstream fdict("dict.txt",std::ios::in);
#define in fin
#define out fout
#define dict fdict
#endif

#include<set>
#include<string>
#include<vector>

std::set<std::string> dictionary;
std::string number;

const char MAP_TABLE[8][3]={	'A','B','C',
								'D','E','F',
								'G','H','I',
								'J','K','L',
								'M','N','O',
								'P','R','S',
								'T','U','V',
								'W','X','Y'};

bool tryPosition(std::string &word,int position){
	if(position==number.length()){
#ifdef DEBUG
		out<<">\t"<<word<<std::endl;
#endif
		if(dictionary.find(word)!=dictionary.end()){
			out<<word<<std::endl;
			return true;
		}
		return false;
	}
	bool found=false;
	for(int i=0;i<3;i++){
		word[position]=MAP_TABLE[number[position]-'2'][i];
		if(tryPosition(word,position+1))
			found=true;
	}
	return found;
}

int main(){
	while(!dict.eof()){
		std::string word;
		dict>>word;
		dictionary.insert(word);
	}
	in.clear();
	in>>number;
	std::string word=number;
	if(!tryPosition(word,0))
		out<<"NONE"<<std::endl;
	return 0;
}