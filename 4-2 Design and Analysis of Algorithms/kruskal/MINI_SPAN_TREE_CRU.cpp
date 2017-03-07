
#include<iostream>
#include<stdlib.h>
#include<queue>
#include<ctime>
#include<cstring>

using namespace std;
#define MAX_VEXNUM 5
#define MAX_WEIGHT 9
typedef enum{
	DG,DN,UDG,UDN
}GraphType;
typedef struct MGraph{
	int vexNum;
	int arcNum;
	int adjM[MAX_VEXNUM][MAX_VEXNUM];
	GraphType type;
}MGraph;
typedef struct{
	int fromVex;
	int toVex;
	int weight;
}Edge;
bool initGraph(MGraph &MG)
{
	MG.vexNum=MG.arcNum=0;
	for(int i=0;i<=MAX_VEXNUM-1;i++)
	{
		for(int j=0;j<=MAX_VEXNUM-1;j++)
		MG.adjM[i][j]=0;
	}
}
bool createMG(MGraph &MG,int vexs)
{
	int arc_count=0;
	srand(time(NULL));
	cout<<"Creating MG_DG by hands(0/1 only):"<<endl;
	cout<<"vexs:"<<vexs<<endl;
	MG.type = UDG;
	MG.vexNum = vexs;
	MG.arcNum = 0;
	for(int row = 0; row <=MAX_VEXNUM -1 ;row++)
    {
        for(int col = row;col <=MAX_VEXNUM - 1;col++)
        {
            if(row == col)
                MG.adjM[row][col] = MAX_WEIGHT;
            else
            {
                MG.adjM[row][col] = rand()%MAX_WEIGHT + 1; // 随机数创建矩阵
                MG.adjM[col][row] = MG.adjM[row][col];
                if(MG.adjM[row][col]!=MAX_WEIGHT)
                    MG.arcNum++;
            }
        }
    }
}

int cmp(const void*p1,const void*p2)
{
	Edge *a=(Edge*) p1;
	Edge *b=(Edge*) p2;
	int result=0;
	if(a->weight>b->weight)
		return 1;
	return -1;
}

void MiniSpanTree_Crus(MGraph &MG)
{
	//MG is UDN
	Edge arr_Edge[MG.vexNum*(MG.vexNum-1)/2];
	int countWeight=0;
	int p=0;
	for(int row=0;row<=MG.vexNum-1;row++)
	{
		for(int col=row+1;col<=MG.vexNum-1;col++)
		{
			arr_Edge[p].weight=MG.adjM[row][col];
			arr_Edge[p].fromVex=row;
			arr_Edge[p].toVex=col;
			p++;
		}
	}
	int check[MG.vexNum]; // check数组负责统计每个顶点所在的集合
	for(int i =0 ;i<=MG.vexNum-1;i++)
        check[i] = i;
	qsort(arr_Edge,p,sizeof(Edge),cmp);
	int count_arc=0;
	int m,n;
	for(int i=0;i<=p-1;i++)
	{
	    if(arr_Edge[i].weight == MAX_WEIGHT) continue;
	    for( m = arr_Edge[i].fromVex; m != check[m]; m = check[m]) check[m] = check[check[m]];
	    for( n = arr_Edge[i].toVex; n != check[n]; n = check[n]) check[n] = check[check[n]];
		if( m == n ) continue; // 如果始点所在和集合和终点所在集合不同，那么可以增加此边
		else
		{
			check[n] = m;
			count_arc++;
			countWeight+=arr_Edge[i].weight;
			cout<<"vex"<<arr_Edge[i].fromVex<<"<->"<<arr_Edge[i].toVex<<endl;
			if(count_arc==MG.vexNum-1)
			{
				cout<<"Cru_Mini_Weight:"<<countWeight<<endl;
				return ;
			}
		}
	}
	cout<<"Error_Cru"<<endl;
	return ;
}
void printGraph(MGraph &MG)
{
	cout<<"---"<<endl;
	cout<<"MG:"<<endl;
	for(int row=0;row<=MG.vexNum-1;row++)
	{
		for(int col=0;col<=MG.vexNum-1;col++)
		{
			cout<<MG.adjM[row][col]<<" ";
		}
		cout<<endl;
	}
	cout<<"arcNum:"<<MG.arcNum<<endl;
	cout<<"vexNum:"<<MG.vexNum<<endl;
	cout<<"---"<<endl;
}

int main(void)
{
	MGraph MG;
	initGraph(MG);
	createMG(MG,MAX_VEXNUM); //可通过修改宏来改变顶点个数
	printGraph(MG);
	MiniSpanTree_Crus(MG);
	return 0;
}
