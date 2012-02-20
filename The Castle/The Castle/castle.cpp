/*
ID:   pinepar1
PROG: castle
LANG: C++
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

#define FILEIO

#ifdef FILEIO
	FILE *in=fopen("castle.in","r"),*out=fopen("castle.out","w");
	#define scanf(...) fscanf(in,__VA_ARGS__)
	#define printf(...) fprintf(out,__VA_ARGS__)
#endif

int width,height;

const int SIZE_LIMIT=50;
int floor[SIZE_LIMIT][SIZE_LIMIT];
int flag[SIZE_LIMIT][SIZE_LIMIT];

const int ROOM_LIMIT=SIZE_LIMIT*SIZE_LIMIT;
int roomSize[ROOM_LIMIT];
int roomNum;

const int DIR_NUM=4;
const int ROW_INC[4]={	0 ,		-1,		0,		1		};
const int COL_INC[4]={	-1,		0 ,		1,		0		};
//						WEST	NORTH	EAST	SOUTH

int fill(int row,int col,int id){
	flag[row][col]=id;
	int area=1;
	for(int dir=0;dir<DIR_NUM;dir++){
		int mask=1<<dir;
		int result=floor[row][col]&mask;
		if(result==0){
			int nextRow=row+ROW_INC[dir];
			int nextCol=col+COL_INC[dir];
			if(nextRow>=0 && nextRow<height && nextCol>=0 && nextCol<width && flag[nextRow][nextCol]==-1)
				area+=fill(nextRow,nextCol,id);
		}
	}
	return area;
}

int main(){
	scanf("%d%d",&width,&height);
	for(int row=0;row<height;row++)
		for(int col=0;col<width;col++){
			scanf("%d",&floor[row][col]);
			flag[row][col]=-1;
		}
	roomNum=0;
	int roomSizeMax=0;
	for(int row=0;row<height;row++)
		for(int col=0;col<width;col++)
			if(flag[row][col]==-1){
				roomSize[roomNum]=fill(row,col,roomNum);
				if(roomSizeMax<roomSize[roomNum])
					roomSizeMax=roomSize[roomNum];
				roomNum++;
			}
	printf("%d\n%d\n",roomNum,roomSizeMax);
	int possibleRoomSizeMax=0;
	int removeRow,removeCol,removeDir;
	for(int col=0;col<width;col++)
		for(int row=height-1;row>=0;row--)
			for(int dir=1;dir<=2;dir++)
				if(floor[row][col]&(1<<dir)){
					int nextRow=row+ROW_INC[dir];
					int nextCol=col+COL_INC[dir];
					if(nextRow>=0 && nextRow<height && nextCol>=0 && nextCol<width){
						int neighbor=flag[nextRow][nextCol];
						int current=flag[row][col];
						if(current!=neighbor){
							int size=roomSize[current]+roomSize[neighbor];
							if(possibleRoomSizeMax<size){
								possibleRoomSizeMax=size;
								removeRow=row;
								removeCol=col;
								removeDir=dir;
							}
						}
					}
				}
	printf("%d\n",possibleRoomSizeMax);
	printf("%d %d %c\n",removeRow+1,removeCol+1,(removeDir==1)?'N':'E');
#ifdef FILEIO
	fclose(in);
	fclose(out);
#endif
	return 0;
}