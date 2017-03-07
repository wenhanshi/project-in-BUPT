
#include<iostream>
#include<stdlib.h>
#include<queue>
#include<ctime>
#include<cstring>

using namespace std;
#define MAX_VEXNUM 6
#define MAX_WEIGHT 9
#define MAX_VALUE 999
typedef enum{
	DG,DN,UDG,UDN
}GraphType;
typedef struct MGraph{
	int vexNum;
	int arcNum;
	int adjM[MAX_VEXNUM][MAX_VEXNUM];
	GraphType type;
}MGraph;
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
struct queue_node{
    int last_v; // 路径中上一个结点
    int value; // 累积价值
    int city; // 当前所在的城市
    int check[MAX_VEXNUM]; // 路径集合
};
typedef struct queue_node QUEUE_NODE;
void init( int check[],int len)
{
    for(int i = 0;i<=len-1;i++)
    {
        check[i] = -1;
    }
}
bool all_find(int path[],int path_size,int start)
{
    for(int i=0;i<=path_size-1;i++)
    {
        if(i == start) continue;
        if(path[i]<0) return false;
    }
    return true;
}
int TSP(MGraph &MG,int path[],int path_size,int start_v)
{
    queue<QUEUE_NODE> q;
    QUEUE_NODE tempNode;
    tempNode.last_v = -1;
    tempNode.value = 0;
    tempNode.city = start_v;
    init(tempNode.check,path_size);
    int mini_tsp = MAX_VALUE;
    int final_last;
    q.push(tempNode);
    while(!q.empty())
    {
        tempNode = q.front();
        q.pop();
        if(tempNode.city == start_v && all_find(tempNode.check,path_size,start_v) && tempNode.value < mini_tsp)
        {
            mini_tsp = tempNode.value;
            final_last = tempNode.last_v;
            memcpy(path,tempNode.check,path_size*sizeof(int));
            path[start_v] = tempNode.last_v;
            //cout<<"find path"<<endl;
        }
        else
        {
            //cout<<"here"<<endl;
            if(tempNode.value > mini_tsp);
            else
            {
                for(int c = 0;c<=MAX_VEXNUM-1;c++)
                {
                    if(MG.adjM[tempNode.city][c] == MAX_WEIGHT
                       || tempNode.check[c] >= 0);
                    else
                    {
                        QUEUE_NODE arr_node;
                        memcpy(arr_node.check,tempNode.check,path_size*sizeof(int));
                        arr_node.city = c;
                        arr_node.last_v = tempNode.city;
                        arr_node.value = tempNode.value + MG.adjM[tempNode.city][c];
                        arr_node.check[c] = tempNode.city;
                        q.push(arr_node);
                        //cout<<"push"<<endl;
                    }
                }
            }
        }
    }
    return mini_tsp;
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
void find_path(int path[],int path_size,int start)
{
    for(int i = path[start];i != start;i = path[i])
        cout<<i<<"<-";
    cout<<start<<"(begin)"<<endl;
}
int main(void)
{
    int tsp;
    int path[MAX_VEXNUM];
	MGraph MG;
	initGraph(MG);
	createMG(MG,MAX_VEXNUM); //可通过修改宏来改变顶点个数
	printGraph(MG);
	tsp = TSP(MG,path,MAX_VEXNUM,0);
	if(tsp != MAX_WEIGHT)
        find_path(path,MAX_VEXNUM,0);
	cout<<"TSP:"<<tsp<<endl;
	return 0;
}
