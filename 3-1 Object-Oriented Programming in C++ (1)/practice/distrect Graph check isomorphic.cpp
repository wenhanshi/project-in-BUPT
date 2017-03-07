#include<iostream>
#define LOOP(G,i,j) for(G.arcM[i][j]=0;G.arcM[i][j]<=1;G.arcM[i][j]++)
using namespace std;
const int vNum=4;
typedef struct DG{
	int arcM[vNum][vNum];
	int arcNum;
}DG;

int save[2000][vNum][vNum];
int count=0;

bool match(int a[vNum][vNum],int b[vNum][vNum])
{
	for(int row=0;row<=vNum-1;row++)
	{
		for(int col=0;col<=vNum-1;col++)
		{
			if(a[row][col]!=b[row][col])
			return 0;
		}
	}
	return 1;
}
bool copy(int to[vNum][vNum],int from[vNum][vNum])
{
	for(int row=0;row<=vNum-1;row++)
	{
		for(int col=0;col<=vNum-1;col++)
		{
			to[row][col]=from[row][col];
		}
	}
	return 1;
}
bool turn(DG &G,int fi,int fj,int fk,int fl)
{
	DG newG;
	copy(newG.arcM,G.arcM);
	newG.arcNum=G.arcNum;
	int nr,nc;
	for(int row=0;row<=vNum-1;row++)
	{
		for(int col=0;col<=vNum-1;col++)
		{
			if(row==0) nr=fi;
			if(row==1) nr=fj;
			if(row==2) nr=fk;
			if(row==3) nr=fl;
			if(col==0) nc=fi;
			if(col==1) nc=fj;
			if(col==2) nc=fk;
			if(col==3) nc=fl;
			newG.arcM[nr][nc]=G.arcM[row][col];
		}
	}
	for(int i=0;i<=count-1;i++)
	{
		if(match(newG.arcM,save[i]))
		return 0;
	}
	return 1;
}



int main(void)
{
	DG G;
	G.arcM[0][0]=G.arcM[1][1]=G.arcM[2][2]=G.arcM[3][3]=0;
		LOOP(G,0,1){
			LOOP(G,0,2){
				LOOP(G,0,3){
					LOOP(G,1,0){
						LOOP(G,1,2){
							LOOP(G,1,3){
								LOOP(G,2,0){
									LOOP(G,2,1){
										LOOP(G,2,3){
											LOOP(G,3,0){
												LOOP(G,3,1){
													LOOP(G,3,2){
														if(turn(G,0,1,2,3)&&
															turn(G,0,1,3,2)&&
															turn(G,0,2,1,3)&&
															turn(G,0,2,3,1)&&
															turn(G,0,3,1,2)&&
															turn(G,0,3,2,1)&&
															turn(G,1,0,2,3)&&
															turn(G,1,0,3,2)&&
															turn(G,1,2,0,3)&&
															turn(G,1,2,3,0)&&
															turn(G,1,3,0,2)&&
															turn(G,1,3,2,0)&&
															turn(G,2,0,1,3)&&
															turn(G,2,0,3,1)&&
															turn(G,2,1,3,0)&&
															turn(G,2,1,0,3)&&
															turn(G,2,3,0,1)&&
															turn(G,2,3,1,0)&&
															turn(G,3,0,1,2)&&
															turn(G,3,0,2,1)&&
															turn(G,3,1,0,2)&&
															turn(G,3,1,2,0)&&
															turn(G,3,2,0,1)&&
															turn(G,3,2,1,0))
															{
																copy(save[count],G.arcM);
																count++;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		
	cout<<count;
		return 0;
}
