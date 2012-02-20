/*
ID:   pinepar1
PROG: ariprog
LANG: C++
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>

#define FILEIO

#ifdef FILEIO
	FILE *in=fopen("ariprog.in","r"),*out=fopen("ariprog.out","w");
	#define scanf(...) fscanf(in,__VA_ARGS__)
	#define printf(...) fprintf(out,__VA_ARGS__)
#endif

const int BOUND_MAX=250;
const int VALUE_MAX=BOUND_MAX*BOUND_MAX*2;
const int LIST_SIZE_MAX=BOUND_MAX*(BOUND_MAX+1)/2;
bool inList[VALUE_MAX+1];
int list[LIST_SIZE_MAX];

struct Sequence{
	int first,difference;
};

struct SequenceLess{
	bool operator()(const Sequence& left,const Sequence& right) const{
		if(left.difference!=right.difference)
			return left.difference<right.difference;
		return left.first<right.first;
	}
};

const int SEQUENCE_NUM_MAX=LIST_SIZE_MAX;
Sequence sequences[SEQUENCE_NUM_MAX];

int main(){
	int length,bound;
	scanf("%d%d",&length,&bound);
	int max=bound*bound*2;
	std::fill(inList,inList+max+1,false);
	int size=0;
	for(int p=0;p<=bound;p++)
		for(int q=p;q<=bound;q++){
			int value=p*p+q*q;
			if(!inList[value]){
				inList[value]=true;
				list[size++]=value;
			}
		}
	std::sort(list,list+size);
	int sequenceNum=0;
	for(int i=0;i<size;i++)
		for(int j=i+1;j<size;j++){
			int first=list[i],second=list[j];
			int difference=second-first;
			int last=first+(length-1)*difference;
			if(last>max)
				break;
			bool satisfied=true;
			for(int i=3;i<=length;i++){
				int next=first+(i-1)*difference;
				if(!inList[next]){
					satisfied=false;
					break;
				}
			}
			if(satisfied){
				sequences[sequenceNum].first=first;
				sequences[sequenceNum].difference=difference;
				sequenceNum++;
			}
		}
	std::sort(sequences,sequences+sequenceNum,SequenceLess());
	if(sequenceNum==0)
		printf("NONE\n");
	else
		for(int i=0;i<sequenceNum;i++)
			printf("%d %d\n",sequences[i].first,sequences[i].difference);
#ifdef FILEIO
	fclose(in);
	fclose(out);
#endif
	return 0;
}