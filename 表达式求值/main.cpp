#include<iostream>
#include<Windows.h>
#include "SqStack.h"
using namespace std;

char pause;

//运算符的优先级比较
char Precede(char t1, char t2) {
	char f;
	switch (t2)
	{
	case '+':
	case '-':
		if (t1 == '{' || t1 == '=')
			f = '<';
		else
		{
			f = '>';
		}
		break;
	case '*':
	case '/':
		if (t1 == '*' || t1 == '/' || t1 == ')')
			f = '>';
		else
		{
			f = '<';
		}
		break;
	case '(':
		if (t1 == ')') {
			cout << "ERROR1" << endl;
			exit(0);
		}
		else
		{
			f = '<';
		}
		break;
	case ')':
		switch (t1)
		{
		case '(':
			f = '=';
			break;
		case '=':
			cout << "ERROR2" << endl;
			exit(0);
		default:
			f='>';
		}
		break;
	case '=':
		switch (t1)
		{
		case '=':
			f = '=';
			break;
		case '(':
			cout << "ERROR2" << endl;
			exit(0);
		default:
			f = '>';
		}

	default:
		break;
	}
	return f;
}

//判断c是否有运算符
int In(char c) {
	switch (c)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '(':
	case ')':
	case '=':
		return 1;
	default:
		return 0;
		
	}
}

//实施一次运算
float Operate(float a, char theta, float b) {
	float c = 0.0f;
	switch (theta)
	{
	case '+':
		c = a + b;
		break;
	case '-':
		c = a - b;
		break;
	case '*':
		c = a * b;
	case '/':
		c = a / b;
	default:
		break;
	}
	return c;
}

//中缀表达式求值，设OPTR和OPND分别为运算符栈和运算数栈
float Val_Exp(char* exp) {
	SqStack<char>OP(20);
	SqStack<float> OD(20);
	char theta;
	float a, b, d;
	//存放由键盘接收的字符
	char c, x;
	//存放浮点数字符串
	char z[6];
	int i;
	//=是表达式结束的标志
	OP.Push('=');
	c = *exp++;
	x = OP.GetTop();
	while (c!='='||x!='=')
	{
		//是7种运算符之一
		if (In(c)) {
			switch (Precede(x,c))
			{
				//栈顶元素优先权低
			case '<':
				OP.Push(c);
				c = *exp++;
				break;
				//脱括号并接收下一个字符
			case '=':
				x = OP.Pop();
				c = *exp++;
				break;
				//退栈并将运算结果入栈
			case '>':
				theta = OP.Pop();
				b = OP.Pop();
				a = OD.Pop();
				OD.Push(Operate(a, theta, b));

			default:
				break;
			}
		}
		//c是操作数
		else if (c >= '0' && c <= '9' || c == '.') {
			i = 0;
			do {
				z[i] = c;
				i++;
				c = *exp++;
			} while (c >= '0' && c <= '9' || c == '.');
			z[i] = '\0';
			//将字符串数组转为浮点型存于d
			d = atof(z);
			OD.Push(d);
		}
		//c是非法字符
		else
		{
			cout << "ERROR3" << endl;
			exit(0);
		}
		x = OP.GetTop();
	}
	d = OD.GetTop();
	return d;
}

//由中缀式求后缀式
void CreatePostExp(char* exp, char*& postexp) {
	char c, x;
	int i = 0;
	SqStack<char>OP(20);
	//=是表达式结束的标志
	OP.Push('=');
	cout << "exp:" << exp << endl;
	c = *exp++;
	while (c)
	{
		if ((c >= '0' && c <= '9') || c == '.') {
			postexp[i++] = c;
			c = *exp++;
		}
		//是7种运算符之一
		if (In(c)) {
			postexp[i++] = ' ';
			x = OP.GetTop();
			switch (Precede(x, c))
			{
			case '<':
				//栈顶元素优先权低
				OP.Push(c);
				c = *exp++;
				break;
			case '=':
				//脱括号并接收下一个字符
				x = OP.Pop();
				c = *exp++;
				break;
			case '>':
				//运算符出栈输出
				postexp[i++] = OP.Pop();
				break;
			default:
				break;
			}
		}
		postexp[i] = '\0';
	}
	cout << "后缀表达式为：" << postexp << endl;
}

//后缀表达式求值
float Val_PostExp(char* postexp) {
	int i;
	char z[6];
	float v = 0, d = 0, a, b;
	char c;
	SqStack<float>OD(20);
	c = *postexp++;
	while (c!='\0')
	{
		//为操作数
		if ((c >= '0' && c <= '9') || c == '.') {
			i = 0;
			do {
				z[i++] = c;
				c = *postexp++;
			} while (c >= '0' && c <= '9' || c == '.');
			z[i] = '\0';
			//将字符串数组转为浮点型存于d
			d = atof(z);
			OD.Push(d);
		}
		//c为运算符
		if (In(c)) {
			b = OD.Pop();
			a = OD.Pop();
			OD.Push(Operate(a, c, b));
			c = *postexp++;
		}
		c = *postexp++;
	}
	v = OD.Pop();
	return v;
}

int main() {
	char exp[20] = "(2.2+5)+4*(5-3.1)=";
	char* postexp;
	postexp = new char[20];
	*postexp = '\0';
	float v1;
	system("cls");
	int choice;
	do {
		cout << "1-创建表达式\n";
		cout << "2-表达式求值\n";
		cout << "3-求后缀表达式\n";
		cout << "4-后缀表达式求值\n";
		cout << "5-显示表达式\n";
		cout << "6-退出\n";
		cout << "Enter choice:";
		cin >> choice;
		switch (choice)
		{
			//创建表达式
		case 1:
			cout << "请输入表达式，以=结束" << endl;
			cin >> exp;
			cin.get(pause);
			system("pause");
			break;
			//表达式求值
		case 2:
			v1 = Val_Exp(exp);
			cout << exp;
			cout << v1 << endl;
			cin.get(pause);
			system("pause");
			break;
			//求后缀表达式
		case 3:
			CreatePostExp(exp, postexp);
			cin.get(pause);
			system("pause");
			break;
			//后缀表达式求值
		case 4:
			v1 = Val_PostExp(postexp);
			cout << postexp << "=" << v1 << endl;
			cin.get(pause);
			system("pause");
			break;
			//显示表达式
		case 5:
			cout << endl;
			cout << "已创建的表达式为：";
			cout << exp << endl;
			if (strlen(postexp)) {
				cout << "后缀表达式为：";
				cout << postexp << endl;
			}
			cin.get(pause);
			system("pause");
			break;
			//退出
		case 6:
			break;
			//选择不合理
		default:
			cout << "Invalid choice\n";
			break;
		}
	} while (choice != 6);

	return 0;
}