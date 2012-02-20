/*
ID:   pinepar1
PROG: prefix
LANG: C++
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>

#define FILEIO

#ifdef FILEIO
	FILE *in=fopen("prefix.in","r"),*out=fopen("prefix.out","w");
	#define scanf(...) fscanf(in,__VA_ARGS__)
	#define printf(...) fprintf(out,__VA_ARGS__)
#endif

const int PRIMITIVE_NUM_MAX=200,PRIMITIVE_LEN_MAX=10;
int primitiveNum=0;
char primitives[PRIMITIVE_NUM_MAX][PRIMITIVE_LEN_MAX+1];

const int SEQ_LEN_MAX=200000;
int sequenceLen;
char sequence[SEQ_LEN_MAX+1]="";
int prefixLen[SEQ_LEN_MAX+1]={0};

const int LINE_LEN_MAX=76;

int main(){
	while(true){
		scanf("%s",primitives[primitiveNum]);
		if(strcmp(primitives[primitiveNum],".")==0)
			break;
		primitiveNum++;
	}

	char line[LINE_LEN_MAX+1];
	while(scanf("%s",line)!=EOF)
		strcat(sequence,line);
	sequenceLen=strlen(sequence);

	//prefixLen[sequenceLen]=0;
	for(int sequenceIndex=sequenceLen-1;sequenceIndex>=0;sequenceIndex--){
		for(int primitiveIndex=0;primitiveIndex<primitiveNum;primitiveIndex++){
			const char *primitive=primitives[primitiveIndex];
			int primitiveLen=strlen(primitive);
			if(sequenceIndex+primitiveLen<=sequenceLen){
				if(strncmp(sequence+sequenceIndex,primitive,primitiveLen)==0){
					if(prefixLen[sequenceIndex]<prefixLen[sequenceIndex+primitiveLen]+primitiveLen)
						prefixLen[sequenceIndex]=prefixLen[sequenceIndex+primitiveLen]+primitiveLen;
				}
			}
		}
	}
	printf("%d\n",prefixLen[0]);
#ifdef FILEIO
	fclose(in);
	fclose(out);
#endif
	return 0;
}