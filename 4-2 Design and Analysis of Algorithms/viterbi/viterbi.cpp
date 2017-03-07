#include<iostream>
#define MAX_WIDTH 4
#define MAX_INPUT 20
#define MAX_WEIGHT 255
using namespace std;

enum state { Z00 , Z01 , Z10 , Z11 }; // 寄存器状态集
typedef enum state STATE;
enum data { D00 , D01 , D10 ,D11 };  // 数据集 （2,1,3）卷积码 是{0,1} -> {DATA} 的映射
typedef enum data DATA;
struct path_node
{
    STATE last_state; // 上一个状态
    int total_weight; // 当前权重
    DATA data_chose; // 最大似然选择
    int bit_chose; // 译码选择
};
typedef struct path_node PATH_NODE;

PATH_NODE mat[MAX_WIDTH][MAX_INPUT]; // 状态转移矩阵
PATH_NODE output[MAX_INPUT]; // 输出路径
DATA d_input[MAX_INPUT/2]; // DATA形式的纠错数组
int ham_mat[MAX_WIDTH][MAX_WIDTH] = {0,1,1,2,
                                     1,0,2,1,
                                     1,2,0,1,
                                     2,1,1,0}; // 数据集合的海明矩阵

void init_mat(int input[]) // 设置寄存器初始的状态为00
{
    mat[1][0] = {Z11,MAX_WEIGHT,D10,0};
    mat[3][0] = {Z11,MAX_WEIGHT,D10,0};
    if(input[0] == 1 && input[1] == 1)
    {
        mat[0][0] = {Z00,2,D00,0};
        mat[2][0] = {Z00,0,D11,1};
    }
    else if((input[0] == 1 && input[1] == 0) ||
            (input[0] == 0 && input[1] == 1))
    {
        mat[0][0] = {Z00,1,D00,0};
        mat[2][0] = {Z00,1,D11,1};
    }
    else
    {
        mat[0][0] = {Z00,0,D00,0};
        mat[2][0] = {Z00,2,D11,1};
    }
}

int ham(DATA d1 , DATA d2) // 由海明矩阵快速计算海明距离
{
    return ham_mat[d1][d2];
}

DATA int_to_bi(int i,int j)
{
    if(i==1&&j==1)
        return D11;
    if(i==1&&j==0)
        return D10;
    if(i==0&&j==1)
        return D01;
    return D00;
}

void crr(int input[] , int len , int &num_t , STATE &end_state) // viterbi译码过程
{
    int t;
    DATA bi_data;
    int mini_weight = MAX_WEIGHT;
    for(int i = 2 ; i<=len-1;i+=2 )
    {
        t = i/2;
        bi_data = int_to_bi(input[i],input[i+1]);
        //cout<<"bidata:"<<bi_data<<endl;
        if( ham(bi_data,D00) + mat[Z00][t-1].total_weight < ham(bi_data,D11) + mat[Z01][t-1].total_weight ) // 枚举Z00的前一状态，并计算当前最小权重，记录路径选择
        {
            mat[Z00][t].total_weight = ham(bi_data,D00) + mat[Z00][t-1].total_weight; // 两条可能的路径选权重最小的
            mat[Z00][t].last_state = Z00; // 记录路径
            mat[Z00][t].data_chose = D00; // 记录状态选择
            mat[Z00][t].bit_chose = 0; // 记录译码选择
        }
        else
        {
            mat[Z00][t].total_weight = ham(bi_data,D11) + mat[Z01][t-1].total_weight;
            mat[Z00][t].last_state = Z01;
            mat[Z00][t].data_chose = D11;
            mat[Z00][t].bit_chose = 0;
        }
        if( ham(bi_data,D10) + mat[Z10][t-1].total_weight < ham(bi_data,D01) + mat[Z11][t-1].total_weight ) // 同上，枚举Z01
        {
            mat[Z01][t].total_weight = ham(bi_data,D10) + mat[Z10][t-1].total_weight;
            mat[Z01][t].last_state = Z10;
            mat[Z01][t].data_chose = D10;
            mat[Z01][t].bit_chose = 0;
        }
        else
        {
            mat[Z01][t].total_weight = ham(bi_data,D01) + mat[Z11][t-1].total_weight;
            mat[Z01][t].last_state = Z11;
            mat[Z01][t].data_chose = D01;
            mat[Z01][t].bit_chose = 0;
        }
        if( ham(bi_data,D11) + mat[Z00][t-1].total_weight < ham(bi_data,D00) + mat[Z01][t-1].total_weight ) // 同上，枚举Z10
        {
            mat[Z10][t].total_weight = ham(bi_data,D11) + mat[Z00][t-1].total_weight;
            mat[Z10][t].last_state = Z00;
            mat[Z10][t].data_chose = D11;
            mat[Z10][t].bit_chose = 1;
        }
        else
        {
            mat[Z10][t].total_weight = ham(bi_data,D00) + mat[Z01][t-1].total_weight;
            mat[Z10][t].last_state = Z01;
            mat[Z10][t].data_chose = D00;
            mat[Z10][t].bit_chose = 1;
        }
        if( ham(bi_data,D01) + mat[Z10][t-1].total_weight < ham(bi_data,D10) + mat[Z11][t-1].total_weight ) // 同上，枚举Z11
        {
            mat[Z11][t].total_weight = ham(bi_data,D01) + mat[Z10][t-1].total_weight;
            mat[Z11][t].last_state = Z10;
            mat[Z11][t].data_chose = D01;
            mat[Z11][t].bit_chose = 1;
        }
        else
        {
            mat[Z11][t].total_weight = ham(bi_data,D10) + mat[Z11][t-1].total_weight;
            mat[Z11][t].last_state = Z11;
            mat[Z11][t].data_chose = D10;
            mat[Z11][t].bit_chose = 1;
        }
    }
    num_t = t;
    //cout<<"t"<<t<<endl;
    for(int i = 0 ;i <=MAX_WIDTH -1 ;i++)
    {
        //cout<<mat[i][t].total_weight<<" ";
        if(mat[i][t].total_weight < mini_weight)
        {
            end_state = (STATE)i;
            mini_weight = mat[i][t].total_weight;
        }
    }
    //cout<<"end_s: "<<end_state<<endl;
}

void make_output(int ed , STATE end_state) // 倒序构建输出序列
{
    STATE last_s;
    output[ed].data_chose = mat[end_state][ed].data_chose;
    output[ed].bit_chose = mat[end_state][ed].bit_chose;
    last_s = mat[end_state][ed].last_state;
    for(int t = ed - 1 ; t>=0 ; t--)
    {
        output[t].data_chose = mat[last_s][t].data_chose;
        output[t].bit_chose = mat[last_s][t].bit_chose;
        //cout<<"output ["<<t<<"]:"<<output[t]<<"  ";
        last_s = mat[last_s][t].last_state;
        //cout<<"last_s:"<<last_s<<endl;
    }
}

void print_output(int ed) // 打印并输出译码结果
{
    cout<<"The decode result is: "<<endl;
    for(int i = 0;i<=ed;i++)
    {
        if(output[i].data_chose == D00)
            cout<<"00 ";
        else if(output[i].data_chose == D01)
            cout<<"01 ";
        else if(output[i].data_chose == D10)
            cout<<"10 ";
        else cout<<"11 ";
    }
    cout<<endl<<"The original info is: "<<endl;
    for(int i = 0;i<=ed;i++)
    {
        cout<<output[i].bit_chose<<" ";
    }
    cout<<endl;
}

void print_mat(int num)
{
    cout<<"mat:"<<endl;
    for(int row = 0;row<=MAX_WIDTH - 1;row++ )
    {
        for(int col = 0;col<=num;col++)
        {
            cout<<" ls: "<<mat[row][col].last_state
            <<" dc: "<<mat[row][col].data_chose
            <<" tw: "<<mat[row][col].total_weight<<"\t";
        }
        cout<<endl;
    }
}
void make_input(int input[],int len) // 数码结构的转换，方便输出
{
    int p;
    for(int i = 0;i<=len-1;i+=2)
    {
        p = i/2;
        d_input[p] = int_to_bi(input[i],input[i+1]);
    }
}
int count_err(int num) // 计算误码数量
{
    int err = 0;
    for(int i = 0;i<=num;i++)
        err += ham(d_input[i],output[i].data_chose);
    return err;
}
int main(void)
{
    int len;
    int input[MAX_INPUT];
    int err;
    int num;
    STATE end_s;
    cout<<"INPUT YOUR LENTH (EVEN NUMBER) (MAX : 20): "<<endl;
    cin>>len;
    for(int i = 0;i<=len-1;i++)
        cin>>input[i];
    init_mat(input);
    crr(input,len,num,end_s); // 最大似然原则，viterbi算法，构造mat矩阵（路径集合）
    make_output(num,end_s); // 构建输出路径
    make_input(input,len); // 为统计误码做准备
    print_output(num);
    //print_mat(num);
    err = count_err(num); // 统计误码过程
    cout<<"Mistakes:"<<err<<endl;
    return 0;
}
