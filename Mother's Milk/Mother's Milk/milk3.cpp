/*
ID:   pinepar1
PROG: milk3
LANG: C++
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#include<queue>

#define FILEIO

#ifdef FILEIO
	FILE *in=fopen("milk3.in","r"),*out=fopen("milk3.out","w");
	#define scanf(...) fscanf(in,__VA_ARGS__)
	#define printf(...) fprintf(out,__VA_ARGS__)
#endif

int size[3];
bool *hashTable,*possible;

class Buckets{
public:
	Buckets(int a,int b,int c){
		left[0]=a;
		left[1]=b;
		left[2]=c;
	}
	Buckets(const Buckets& another){
		for(int i=0;i<3;i++)
			left[i]=another.left[i];
	}
	int hash(){
		return left[0]*(size[1]+1)+left[1];
	}
	Buckets pour(int from,int to){
		int amount=std::min(size[to]-left[to],left[from]);
		Buckets result(*this);
		result.left[from]-=amount;
		result.left[to]+=amount;
		return result;
	}
	static int hashMax(){
		return size[0]*(size[1]+1)+size[1];
	}
	int left[3];
};

int main(){
	for(int i=0;i<3;i++)
		scanf("%d",size+i);

	int hashMax=Buckets::hashMax();
	hashTable=new bool[hashMax+1];
	std::fill(hashTable,hashTable+hashMax+1,false);

	possible=new bool[size[2]+1];
	std::fill(possible,possible+size[2]+1,false);

	std::queue<Buckets> BFS;
	Buckets begin(0,0,size[2]);
	hashTable[begin.hash()]=true;
	BFS.push(begin);
	while(!BFS.empty()){
		Buckets current=BFS.front();
		BFS.pop();
		if(current.left[0]==0)
			possible[current.left[2]]=true;
		for(int from=0;from<3;from++)
			for(int to=0;to<3;to++){
				if(from==to)
					continue;
				Buckets next=current.pour(from,to);
				if(!hashTable[next.hash()]){
					hashTable[next.hash()]=true;
					BFS.push(next);
				}
			}
	}

	bool first=true;
	for(int i=0;i<=size[2];i++)
		if(possible[i]){
			if(first)
				first=false;
			else
				printf(" ");
			printf("%d",i);
		}
	printf("\n");

	delete[] possible;
	delete[] hashTable;
#ifdef FILEIO
	fclose(in);
	fclose(out);
#endif
	return 0;
}