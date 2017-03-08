#include <iostream>
#include <cmath>
#include <algorithm>
#define BIRD_NUM 14
#define MAX_WEIGHT 9999
#define MAX_USE 9
#define MAX_K 5
using namespace std;

struct bird{
    double wl;
    double bl;
    char label;
};
typedef struct bird BIRD;
struct dir{
    double dest;
    int index;
};
typedef struct dir DIR;
BIRD arr_bird[BIRD_NUM];
char labels[BIRD_NUM] = {'B','B','A','A','B','A','A','B','B','A','B','B','A','B'};
double bird_fit[BIRD_NUM*2] = {
            13.80 , 16.40,
            15.60 , 20.80,
            12.00 , 18.60,
            12.80 , 20.00,
            14.80 , 18.20,
            13.00 , 19.60,
            12.60 , 20.00,
            13.60 , 17.40,
            13.80 , 19.00,
            11.40 , 17.80,
            14.00 , 17.00,
            15.40 , 18.20,
            11.80 , 19.60,
            12.40 , 17.20};
void init_arr(void)
{
    for(int i = 0 ;i <= BIRD_NUM-1 ;i++)
    {
        arr_bird[i].wl = bird_fit[i*2];
        arr_bird[i].bl = bird_fit[i*2+1];
        arr_bird[i].label = labels[i];
    }
    //for(int i = 0 ;i <= BIRD_NUM -1 ;i++)
    //{
    //    cout<<i<<":"<<arr_bird[i].bl<<","<<arr_bird[i].wl<<":"<<arr_bird[i].label<<endl;
    //}
}
bool cmp(DIR &a,DIR &b)
{
      return a.dest<b.dest;

}
char knn(double nwl ,double nbl,int k,int num)
{
    DIR arr_dest[BIRD_NUM];
    int anum = 0, bnum = 0;
    double last_min = MAX_WEIGHT;
    for(int i=0;i<=num-1;i++)
    {
        arr_dest[i].dest = sqrt ( (nwl - arr_bird[i].wl)*(nwl - arr_bird[i].wl)
                        +(nbl - arr_bird[i].bl)*(nbl - arr_bird[i].bl) );
        arr_dest[i].index = i;
    }
    sort(arr_dest,arr_dest+num,cmp);
    //for(int i = 0;i<=num -1 ;i++)
    //    cout<<arr_dest[i].index<<":"<<arr_dest[i].dest<<endl;
    //cout<<endl;
    for(int i = 0;i<=k-1;i++)
    {
        if(arr_bird[arr_dest[i].index].label == 'A') anum++;
        else bnum++;
    }
    if(anum>bnum)
        return 'A';
    return 'B';
}

double check_knn(int num)
{
    int crr = 0;
    char ch;
    for(int i = num;i<=BIRD_NUM-1;i++)
    {
        ch = knn(arr_bird[i].wl,arr_bird[i].bl,MAX_K,num);
        //cout<<"["<<i<<"]:"<<"is:"<<arr_bird[i].label<<"  predict->"<<ch<<endl;
        if(arr_bird[i].label == ch) crr++;
    }
    return crr/(double)(BIRD_NUM-num);
}

int main(void)
{
    double crate;
    char ch;
    init_arr();
    crate = check_knn(MAX_USE);
    cout<<"Rate = "<<crate<<endl;
    ch = knn(14.50,19.00,MAX_K,MAX_USE);
    cout<<"PRE:"<<endl;
    cout<<"14.50,19.00->"<<ch<<endl;
    ch = knn(12.40,18.00,MAX_K,MAX_USE);
    cout<<"12.40,18.00->"<<ch<<endl;
    ch = knn(14.00,20.40,MAX_K,MAX_USE);
    cout<<"14.00,20.40->"<<ch<<endl;
    return 0;
}
