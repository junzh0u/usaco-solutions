/*
ID:   pinepar1
PROG: checker
LANG: C++
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>

#define FILEIO

#ifdef FILEIO
	FILE *in=fopen("checker.in","r"),*out=fopen("checker.out","w");
	#define scanf(...) fscanf(in,__VA_ARGS__)
	#define printf(...) fprintf(out,__VA_ARGS__)
#endif

const int SIZE_LIMIT=13;
int size;
bool columnUsed[SIZE_LIMIT];
bool diagonalLURBUsed[2*SIZE_LIMIT-1];
bool diagonalRULBUsed[2*SIZE_LIMIT-1];
int solution[SIZE_LIMIT];
int solutionNum;
bool usingFlip;

void initialize(){
	scanf("%d",&size);
	usingFlip=(size>6);
	std::fill(columnUsed,columnUsed+size,false);
	std::fill(diagonalLURBUsed,diagonalLURBUsed+2*size-1,false);
	std::fill(diagonalRULBUsed,diagonalRULBUsed+2*size-1,false);
	solutionNum=0;
}

void setUsed(int row,int col,bool status){
	columnUsed[col]=status;
	diagonalLURBUsed[row+col]=status;
	diagonalRULBUsed[row-col+size-1]=status;
}

bool checkUsed(int row,int col){
	return columnUsed[col] || diagonalLURBUsed[row+col] || diagonalRULBUsed[row-col+size-1];
}

void printSolution(){
	for(int row=0;row<size;row++){
		if(row!=0)
			printf(" ");
		printf("%d",solution[row]+1);
	}
	printf("\n");
}

void placeRow(int row){
	if(row>=size){
		if(solutionNum<3)
			printSolution();
		solutionNum++;
		return;
	}
	int ratio=1;
	if(usingFlip){
		if(row==0)
			ratio=2;
		else if(row==1 && solution[0]*2+1==size)
			ratio=2;
	}
	for(solution[row]=0;ratio*solution[row]<size;solution[row]++)
		if(!checkUsed(row,solution[row])){
			setUsed(row,solution[row],true);
			placeRow(row+1);
			setUsed(row,solution[row],false);
		}
}

int main(){
	initialize();
	placeRow(0);
	if(usingFlip)
		solutionNum*=2;
	printf("%d\n",solutionNum);
#ifdef FILEIO
	fclose(in);
	fclose(out);
#endif
	return 0;
}