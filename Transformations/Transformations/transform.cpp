/*
ID: pinepar1
PROG: transform
LANG: C++
*/

#include<iostream>
#include<memory.h>

//#define DEBUG

#ifdef DEBUG
#define in std::cin
#define out std::cout

#else
#include<fstream>
std::ifstream fin("transform.in",std::ios::in);
std::ofstream fout("transform.out",std::ios::out);
#define in fin
#define out fout
#endif

const int SIZE=10;

char before[SIZE][SIZE+1],after[SIZE][SIZE+1];
int size;

void copy(const char from[SIZE][SIZE+1],char to[SIZE][SIZE+1]){
	memcpy(to,from,sizeof(char)*SIZE*(SIZE+1));
}

void rotate90(char square[SIZE][SIZE+1]){
	char temp[SIZE][SIZE+1];
	copy(square,temp);
	for(int row=0;row<size;row++)
		for(int col=0;col<size;col++)
			square[row][col]=temp[size-1-col][row];
}

void rotate180(char square[SIZE][SIZE+1]){
	rotate90(square);
	rotate90(square);
}

void rotate270(char square[SIZE][SIZE+1]){
	rotate90(square);
	rotate90(square);
	rotate90(square);
}

void reflect(char square[SIZE][SIZE+1]){
	char temp[SIZE][SIZE+1];
	copy(square,temp);
	for(int row=0;row<size;row++)
		for(int col=0;col<size;col++)
			square[row][col]=temp[row][size-1-col];
}

bool equal(char left[SIZE][SIZE+1],char right[SIZE][SIZE+1]){
	for(int row=0;row<size;row++)
		for(int col=0;col<size;col++)
			if(left[row][col]!=right[row][col])
				return false;
	return true;
}

bool tryTransformation(int id,char before[SIZE][SIZE+1],char after[SIZE][SIZE+1]){
	char temp[SIZE][SIZE+1];
	copy(before,temp);
	switch(id){
		case 1:
			rotate90(temp);
			return equal(temp,after);
		case 2:
			rotate180(temp);
			return equal(temp,after);
		case 3:
			rotate270(temp);
			return equal(temp,after);
		case 4:
			reflect(temp);
			return equal(temp,after);
		case 5:
			reflect(temp);
			for(int i=1;i<=3;i++)
				if(tryTransformation(i,temp,after))
					return true;
			return false;
		case 6:
			return equal(before,after);
		default:
			return true;
	}
}

int main(){
	in>>size;
	for(int line=0;line<size;line++)
		in>>before[line];
	for(int line=0;line<size;line++)
		in>>after[line];
	for(int i=1;i<=7;i++)
		if(tryTransformation(i,before,after)){
			out<<i<<std::endl;
			break;
		}
	return 0;
}