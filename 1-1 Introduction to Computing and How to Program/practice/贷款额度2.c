#include<stdio.h>
int min(double a, double b)
{
	if (a > b) return b;
	else return a;
}
int main()
{
	double price, area, balance1, balance2, ratio1, ratio2, ratio3, ratio4, deposit1, deposit2, repayment;
	double a, b, c, d, ans, x, y;
	char m, n, o, p;
	int month;
	printf("请输入住房总价（以万元为单位，下同）\n");
	scanf("%lf", &price);
	getchar();
	printf("请输入房屋面积\n");
	scanf("%lf", &area);
	getchar();
	printf("请输入贷款期限\n");
	scanf("%d", &month);
	getchar();
	printf("是否使用配偶公积金\na---是\nb---否\n");
	scanf("%c", &m);
	getchar();
	printf("购买房屋类型是否为公有现住房\na---是\nb---否\n");
	scanf("%c", &p);
	getchar();
	printf("第几套房产\na---第一套\nb---第二套\nc---第三套及以上\n");
	scanf("%c", &n);
	getchar();
	printf("请输入本人公积金余额\n");
	scanf("%lf", &balance1);
	getchar();
	printf("请输入本人公积金月缴存额\n");
	scanf("%lf", &deposit1);
	getchar();
	printf("请输入本人公积金单位缴存比例\n");
	scanf("%lf", &ratio1);
	getchar();
	printf("请输入本人公积金个人缴存比例\n");
	scanf("%lf", &ratio2);
	getchar();
	if (p =='a') b = price*0.7;
	else
	{
		if (n =='a')
		{
			if (area <= 90) b = price*0.8;
			else b = price*0.7;
		}
		else if (n =='b') b = price*0.5;
		else if (n =='c') b = 0;
	}
	if (m =='a')
	{
		printf("请输入配偶公积金余额\n");
		scanf("%lf", &balance2);
		getchar();
		if (balance1 + balance2 >= 2) c = 10 * (balance1 + balance2);
		else c = 20;
		printf("请输入配偶公积金月缴存额\n");
		scanf("%lf", &deposit2);
		getchar();
		printf("请输入配偶公积金单位缴存比例\n");
		scanf("%lf", &ratio3);
		getchar();
		printf("请输入配偶公积金个人缴存比例\n");
		scanf("%lf", &ratio4);
		getchar();
		printf("请输入夫妻双方现有贷款月应还款总额\n");
		scanf("%lf", &repayment);
		getchar();
		a = ((deposit1 / (ratio1 + ratio2) + deposit2 / (ratio3 + ratio4) + deposit1*ratio1 + deposit2*ratio3)*0.4 - repayment)*month;
		printf("本人及配偶是否有补充公积金\na---是\nb---否\n");
		scanf("%c", &o);
		getchar();
		if (o =='a')d = 70;
		else d = 60;
	}
	else if (m =='b')
	{	
		printf("请输入本人现有贷款月应还款总额\n");
		scanf("%lf", &repayment);
		getchar();
		a = ((deposit1 / (ratio1 + ratio2) + deposit1*ratio1)*0.4 - repayment)*month;
		if (balance1>= 2.0) c = 10 * balance1;
		else c = 20;
		printf("本人是否有补充公积金\na---是\nb---否\n");
		scanf("%c", &o);
		getchar();
		if (o =='a') d = 50;
		else if (o =='b') d = 40;
	}
	x=min(a,b);
	y=min(c,d);
	ans = min(x, y);
	if ((int)(ans * 10000) % 1000 > 0)ans += 0.1;
	printf("%.1lf万元\n", ans);
	printf("%lf\n",a);
	printf("%lf\n",b);
	printf("%lf\n",c);
	printf("%lf\n",d);
}

