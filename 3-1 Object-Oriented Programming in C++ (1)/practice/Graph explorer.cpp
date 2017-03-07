// this is your responsibility
#include<iostream>
#include<stdlib.h>
#include<queue>
#include<ctime>
#include<cstring>

using namespace std;
#define MAX_VEXNUM 10
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
bool visited[MAX_VEXNUM];
bool initGraph(MGraph &MG)
{
	MG.vexNum=MG.arcNum=0;
	for(int i=0;i<=MAX_VEXNUM-1;i++)
	{
		for(int j=0;j<=MAX_VEXNUM-1;j++)
		MG.adjM[i][j]=0;
	}
}
bool createMG(MGraph &MG,unsigned int seed,int vexs)
{
	if(vexs<=0)
	{
		cout<<"Can't construct a zero-mem matrix."<<endl;
	}
	else
	{
		int arcs,r_row,r_col;
		srand(seed);
		MG.vexNum=vexs;
		arcs=rand()%(MG.vexNum*MG.vexNum);
		MG.arcNum=arcs;
		for(int i=0;i<=arcs-1;i++)
		{
			r_row=rand()%MG.vexNum;
			r_col=rand()%MG.vexNum;
			if(MG.adjM[r_row][r_col] || r_row==r_col)
			{
				i--;
				continue;
			}
			MG.adjM[r_row][r_col]=1;
		}
		MG.type=DG;
	}
}
int firstAdjVex(MGraph &MG,int v)
{
	for(int w=0;w<=MG.vexNum-1;w++)
	{
		if(MG.adjM[v][w]!=MAX_WEIGHT)
		return w;
	}
	return -1;
}
int nextAdjVex(MGraph &MG,int v,int w)
{
	for(int u=w+1;u<=MG.vexNum-1;u++)
	{
		if(MG.adjM[v][u]!=MAX_WEIGHT)
		return u;
	}
	return -1;
}
bool DFS(MGraph &MG,int v)
{
	cout<<v<<" ";
	visited[v]=1;
	for(int w=firstAdjVex(MG,v);w>=0;w=nextAdjVex(MG,v,w))
	{
		if(!visited[w])
		{
			
			DFS(MG,w);
		}
	}
	return 1;
}
bool dfsTraverse(MGraph &MG)
{
	cout<<"DFS:";
	for(int i=0;i<=MG.vexNum-1;i++)
	{
		visited[i]=0;
	}
	for(int i=0;i<=MG.vexNum-1;i++)
	{
		if(!visited[i])
		DFS(MG,i);
	}
	cout<<endl;
	return 1;
}
bool bfsTraverse(MGraph &MG)
{	
	queue<int> Q;
	int v;
	cout<<"BFS:";
	for(int i=0;i<=MG.vexNum-1;i++)
	{
		visited[i]=0;
	}
	for(int i=0;i<=MG.vexNum-1;i++)
	{
		if(!visited[i])
		{
			cout<<i<<" ";
			visited[i]=1;
			Q.push(i);
			while(!Q.empty())
			{
				v=Q.front();
				Q.pop();
				for(int w=firstAdjVex(MG,v);w>=0;w=nextAdjVex(MG,v,w))
				{
					if(!visited[w])
					{
						cout<<w<<" ";
						visited[w]=1;
						Q.push(w);
					}
				}
			}
		}
	}
	cout<<endl;
	return 1;
}

bool isConnected(MGraph &MG)
{
	int count,test;
	if(MG.type==DG)
	{
		for(int row=0;row<=MG.vexNum-1;row++)
		{
			count=0;
			for(int col=0;col<=MG.vexNum-1;col++)
			{
				count+=MG.adjM[row][col];
				if(count) break;
			}
			if(!count)
			{
				for(int tempr=0;tempr<=MG.vexNum-1;tempr++)
				{
					count+=MG.adjM[tempr][row];
					if(count) break;
				}
				if(!count)
				return 0;
			}
		}
		return 1;
	}
	else if(MG.type==UDN)
	{
		for(int row=0;row<=MG.vexNum-1;row++)
		{
			count=0;
			for(int col=0;col<=MG.vexNum-1;col++)
			{
				count+=MG.adjM[row][col];
			}
			if(count==MG.vexNum*MAX_WEIGHT)
				return 0;
		}
		return 1;
	}
	else
	{
		cout<<"UNKNOWN"<<endl;
	}
}
typedef struct{
	int adj;
	int lowcost;
} closedge;

int mini_Edge(closedge *low,int vexs)
{
	int p=1,min=MAX_WEIGHT;
	for(int i=1;i<=vexs-1;i++)
	{
		if(low[i].lowcost<min)
		{
			min=low[i].lowcost;
			p=i;
		}
	}
	return p;
}
void MiniSpanTree_PRIM(MGraph &MG)//start from v0
{
	bool check[MG.vexNum];
	memset(check,false,sizeof(bool));
		
	int cur_v=0,countWeight=0;
	closedge low[MG.vexNum];
	check[cur_v]=true;
	
	for(int i=1;i<=MG.vexNum-1;i++)
	{
		low[i].adj=cur_v;
		low[i].lowcost=MG.adjM[i][cur_v];
	}
	
	for(int i=1;i<=MG.vexNum-1;i++)
	{
		cur_v=mini_Edge(low,MG.vexNum);
		check[cur_v]=true;
		countWeight+=low[cur_v].lowcost;
		low[cur_v].lowcost=MAX_WEIGHT;
		for(int v=1;v<=MG.vexNum-1;v++)
		{
			if(check[v]==false)
			{
				if(MG.adjM[v][cur_v]<low[v].lowcost)//kernal
				{
					low[v].lowcost=MG.adjM[v][cur_v];
					low[v].adj=cur_v;
				}
			}
		}
	}
	cout<<"PRIM_Mini_Weight:"<<countWeight<<endl;
}
typedef struct{
	int fromVex;
	int toVex;
	int weight;
}Edge;
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
	bool check[MG.vexNum];
	memset(check,false,sizeof(bool));
	
	qsort(arr_Edge,MG.vexNum*(MG.vexNum-1)/2,sizeof(Edge),cmp);
	int count_arc=0;
	for(int i=0;i<=p-1;i++)
	{
		if(check[arr_Edge[i].fromVex]&&check[arr_Edge[i].toVex])
			continue;
		else
		{
			check[arr_Edge[i].fromVex]=check[arr_Edge[i].toVex]=1;
			count_arc++;
			countWeight+=arr_Edge[i].weight;
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
	cout<<"Connected?:"<<isConnected(MG)<<endl;
	cout<<"arcNum:"<<MG.arcNum<<endl;
	cout<<"vexNum:"<<MG.vexNum<<endl;
	cout<<"---"<<endl;
}
bool createMG_Hand_DG(MGraph &MG,int vexs)
{
	int arc_count=0;
	cout<<"Creating MG_DG by hands(0/1 only):"<<endl;
	cout<<"vexs:"<<vexs<<endl;
	MG.type=DG;
	MG.vexNum=vexs;
	for(int row=0;row<=MG.vexNum-1;row++)
	{
		for(int col=0;col<=MG.vexNum-1;col++)
		{
			cin>>MG.adjM[row][col];
			if(MG.adjM[row][col]==1)
			arc_count++;
		}
	}
	MG.arcNum=arc_count;
	return 1;
}
typedef struct{
	int cost;
	bool isFind;
}miniPath;
void findMiniCost(MGraph &MG,miniPath *VT,int &mini_v)
{
	int miniCost=MAX_WEIGHT;
	int flag=0;
	for(int i=0;i<=MG.vexNum-1;i++)
	{
		if(!VT[i].isFind&&VT[i].cost<miniCost)
		{
			mini_v=i;
			flag=1;
		}
	}
	if(!flag) mini_v=-1;
}
void FindMiniPath_DIJ(MGraph &MG,int start_v)
{
	miniPath VT[MG.vexNum];
	int mini_v;
	for(int i=0;i<=MG.vexNum-1;i++)
	{
		VT[i].cost = MAX_WEIGHT;
		VT[i].isFind = false;
	}
	VT[start_v].isFind=true;
	VT[start_v].cost=0;
	for(int v=firstAdjVex(MG,start_v);v>=0;v=nextAdjVex(MG,start_v,v))
	{
		VT[v].cost=MG.adjM[start_v][v];
	}
	while(1)
	{
		findMiniCost(MG,VT,mini_v);
		if(mini_v<0)
			break;
		else
		{
			VT[mini_v].isFind=true;
			for(int v=firstAdjVex(MG,mini_v);v>=0;v=nextAdjVex(MG,mini_v,v))
			{	//v is adj to mini_v
				if(!VT[v].isFind)
				{
					if(VT[mini_v].cost+MG.adjM[mini_v][v]<VT[v].cost)
					{
						VT[v].cost=VT[mini_v].cost+MG.adjM[mini_v][v];
					}
				}
			}
		}
	}
	cout<<"MiniPath_DIJ:"<<endl;
	for(int i=0;i<=MG.vexNum-1;i++)
	{
		cout<<"v"<<i<<":"<<VT[i].cost<<" ";
	}
	cout<<"\n---"<<endl;
} 
int main(void)
{
	MGraph MG;
	initGraph(MG);
	//createMG(MG,time(NULL),5);
	createMG_Hand_DG(MG,4);
	//dfsTraverse(MG);//need change firstAdjVex & nextAdjVex 
	//bfsTraverse(MG);
	printGraph(MG);
	//MiniSpanTree_PRIM(MG);
	//MiniSpanTree_Crus(MG);
	FindMiniPath_DIJ(MG,0); 
	return 0;
}
