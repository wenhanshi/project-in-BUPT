#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

#define MAX_M 3
#define MAX_N 8
#define RAND 9999
#define PI 3.141593

struct cpx // 复数结构
{
    double re;
    double im;
};
typedef struct cpx CPX;

CPX X[MAX_N]; // 寄存器数组，既是输入也是输出

CPX add_cpx(CPX x,CPX y) // 复数加法
{
    CPX temp;
    temp.im = x.im + y.im;
    temp.re = x.re + y.re;
    return temp;
}

CPX sub_cpx(CPX x,CPX y) // 复数减法
{
    CPX temp;
    temp.im = x.im - y.im;
    temp.re = x.re - y.re;
}

CPX mul_with_rtt(CPX x,int exp_W,int width_W) // 由于采用FFT，只需要和旋转因子W做复数乘法
{
    CPX temp;
    temp.re = x.re * cos(2.0 * PI * exp_W / MAX_N) + x.im * sin(2.0 * PI * exp_W / MAX_N);
    temp.im = x.im * cos(2.0 * PI * exp_W / MAX_N) - x.re * sin(2.0 * PI * exp_W / MAX_N);
    return temp;
}

void print_cpx(void) // 打印函数
{
    for(int i = 0; i <= MAX_N - 1 ; i++)
        cout<<"X["<<i<<"]: "<<"("<<X[i].re<<")"<<"+"<<"i*("<<X[i].im<<")"<<endl;
}

void inv_input(int len) // 由于是DIT-FFT 需要使用算法对输入进行倒置译码
{
    CPX temp;
    int bit_w = MAX_N / 2;
    int step;
    for(int i = 1 ; i<= len-2 ; i++)
    {
        if( i < bit_w )
        {
            temp = X[i];
            X[i] = X[bit_w];
            X[bit_w] = temp;
            cout<<"exchange"<<i<<"->"<<bit_w<<endl;
        }
        step = MAX_N / 2;
        jump:
        if(bit_w < step)
        {
            bit_w += step;
        }
        else
        {
            bit_w -= step;
            step /= 2;
            goto jump;
        }
    }
}
void DIT_FFT(int len,int log_len) // DIT-FFT过程
{
    int step; // 当前步进
    CPX add1,add2; // 蝶型运算的两个加法元
    int exp_w; // 旋转因子W的指数
    for(int L = 1;L<=log_len;L++)
    {
        step = (int)pow(2,L-1);
        for(int j = 0;j<=step - 1;j++)
        {
            exp_w = j * (int)pow(2,log_len-L);
            for(int k = j ; k<=MAX_N -1;k+=2*step)
            {
                add2 = mul_with_rtt(X[k+step],exp_w,MAX_N);
                add1 = X[k];
                X[k] = add_cpx(add1,add2); // 蝶型运算 ，步进为step，实质上是奇偶分治
                X[k+step] = sub_cpx(add1,add2);
            }
        }
    }
}

int main(void)
{
    srand(time(NULL));
    cout<<"---   INPUT :"<<endl;
    for(int i = 0 ;i<=MAX_N - 1 ;i++) // 随机产生采样值
    {
        X[i].re = rand()%(RAND + 1) / (double)(RAND + 1);
        X[i].im = rand()%(RAND + 1) / (double)(RAND + 1);
    }
    print_cpx();
    inv_input(MAX_N); // 倒置译码
    cout<<"---   INPUT AFTER THE EXCHANGE :"<<endl;
    print_cpx();
    DIT_FFT(MAX_N,MAX_M); // 基2的DIT-FFT
    cout<<"---   RESULT: "<<endl;
    print_cpx();
    return 0;
}
