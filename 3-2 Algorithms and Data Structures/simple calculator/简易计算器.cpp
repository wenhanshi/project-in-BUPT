#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<stack>
#include<cstdio>
#include<cstdlib>
using namespace std;
const double PI = M_PI;
const double e = 2.718281828;

void input_equation(char input[])
//输入去除空格
{
	char tmp;
	int len = 0;
	while ((tmp = getchar()) != '\n')
		if (tmp != ' ')
			input[len++] = tmp;
	input[len] = '\0';
	return;
}

bool check_bracket(char input[])
//检查括号是否配对
{
	stack<char> stk;
	stk.push('\0');
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == '(')
			stk.push('(');
		else if (input[i] == ')')
		{
			if (stk.top() == '(')
				stk.pop();
			else
				return false;
		}
	}
	if (stk.top() == '\0')
		return true;
	return false;
}

bool check(char input[])
//初步检查输入是否合法
{
	if (input[strlen(input) - 1] != '=')
		return false;
	if (!check_bracket(input))
		return false;
	return true;
}

bool unary_operation(int op, double& x)
//单目运算符
{
	switch (op)
	{
	case 0: return true;
	case 8: x=sin(x); return true;
	case 9: x=cos(x); return true;
	case 10: x=tan(x); return true;
	case 11: if (x <= 0.0) return false; x = log10(x); return true;
	case 12: if (x <= 0.0) return false; x = log(x); return true;
	case 13: x = -x; return true;
	}
}

bool binocular_operation(int op, double& x, double y)//前缀单目运算符的运算定义
//双目运算符
{
	switch (op)
	{
	case 2: x = x + y; return true;
	case 3: x = x - y; return true;
	case 4: x = x * y; return true;
	case 5: if (fabs(y - 0.0) < 1e-10) return false; else x = x / y; return true;
	case 6: x = pow(x, y); return true;
	}
}

bool priority(int op_in_stk, int op_to_be_pushed)
//运算优先级
{
	if (op_in_stk == 14)
    //遇到左括号或者栈外运算符比站内运算符优先级高，则直接入栈
		return false;
    if (op_in_stk <= 6 && op_to_be_pushed <= 6)
    //两者都是双目运算符
    {
        if (op_in_stk / 2 < op_to_be_pushed / 2)
        //0和1同优先级，2和3同优先级，4和5同优先级，6优先级最高
            return false;
        else
            return true;
    }
	else if (op_in_stk <= 6 && op_to_be_pushed > 6)
        return false;
    else if (op_in_stk > 6 && op_to_be_pushed <= 6)
        return true;
    else
    //两者都是单目运算符，则直接压栈
        return false;
}

bool calculate(char input[])
{
	stack<double> number;
	stack<int> operation;
	operation.push(0);//把等号压入栈中

	for (int i = 0; i < strlen(input); i++)
	{
		if ((input[i] == 'p' || input[i] == 'P') && (input[i + 1] == 'i' || input[i + 1] == 'I'))
		//允许用户不分大小写地输入pi
		{
			number.push(PI);
			i++;
		}
		else if (input[i] == 'e')
		//常数e
			number.push(e);
		else if (input[i] >= '0' && input[i] <= '9' || input[i] == '.')
		//数字
		{
			double num = 0.0;
			while (input[i] >= '0' && input[i] <= '9')
			{
				num = num * 10 + input[i] - '0';
				i++;
			}
			if (input[i] == '.')
			{
				double power = 1;
				i++;
				while (input[i] >= '0' && input[i] <= '9')
				{
					power /= 10;
					num += power * (input[i] - '0');
					i++;
				}
			}
			number.push(num);
			i--;
		}
		else
        //运算符处理
		{
			int op_to_be_pushed = -1;
			char s_opration[15][5] = { "=", ")", "+", "-", "*", "/", "^", "\0", "sin", "cos", "tan", "log", "ln", "~", "(" };
			for (int j = 0; j <= 14; j++)
				if (j == 7) continue;
				else if (strncmp(&input[i], s_opration[j], strlen(s_opration[j])) == 0)
				{
					op_to_be_pushed = j;
					i += strlen(s_opration[j]) - 1;
					break;
				}
			if (op_to_be_pushed == -1)
            //输入没有匹配
				return false;
			while (!operation.empty() && priority(operation.top(), op_to_be_pushed))
			{
				int op_in_stk = operation.top();
				operation.pop();
				if (op_in_stk >= 8 && op_in_stk <= 13 || op_in_stk == 0)
				//单目运算符的处理
				{
					double num;
					if (!number.empty())
					{
						num = number.top();
						number.pop();
					}
					else
						return false;
					if (!unary_operation(op_in_stk, num))
                        return false;
					number.push(num);
				}
				else
                //双目运算符的处理
				{
					double num1, num2;
					if (!number.empty())
					{
						num1 = number.top();
						number.pop();
					}
					else
						return false;
					if (!number.empty())
					{
						num2 = number.top();
						number.pop();
					}
					else
						return false;
					if (!binocular_operation(op_in_stk, num2, num1))
                        return false;
					number.push(num2);
				}
			}
			if (op_to_be_pushed == 1)
            //待入栈运算符为右括号则把栈顶的左括号给弹出
				operation.pop();
			else
			//否则压栈
				operation.push(op_to_be_pushed);
		}
	}
	if (number.size() != 1)
        return false;
	cout << input;
	if (fabs(ceil(number.top())-number.top()) < 1e-8)
        cout << ceil(number.top()) << endl;
    else if (fabs(floor(number.top())-number.top()) < 1e-8)
        cout << floor(number.top()) << endl;
    //如果和最近整数差值小于10^-8则输出整数
    else
        cout << number.top() << endl;
	return true;
}

int main(void)
{
	char input[1000];
	bool flag;
	cout << "简单计算器 ver.yjbbrqw\n"
        << "简易使用说明：\n"
        << "1.本计算器可以实现基本的加减乘除乘方开方，以及sin, cos, tan, ln, log运算。\n"
        << "2.输入算式时，所有空格将被忽略，且请保证算式末尾为'='，左右括号匹配（请勿省略算式末尾的')'。\n"
        << "3.提供基本常数的pi与e可以直接输入。\n"
        << "4.若要输入负号非减号，请输入~来代替负号。\n"
        << "5.若要开方，请保证被开方数大于0。\n"
        << "6.若浮点数整数部分为零，则可以省略这个零，比如.1234\n"
        << "7.输入exit回车即可退出程序。\n";
    system("pause");
	while (1)
    {
        cout << "请输入算式：\n";
		input_equation(input);
		if (strcmp(input, "exit") == 0)
            return 0;
		flag = check(input);
		if (flag)
			flag = calculate(input);
		if (!flag)
			cout << "输入有误，请重新输入。\n";
	}
	return 0;
}

