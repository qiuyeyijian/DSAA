#include<iostream>
#include<Windows.h>
#include "SqStack.h"
using namespace std;

char pause;

//����������ȼ��Ƚ�
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

//�ж�c�Ƿ��������
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

//ʵʩһ������
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

//��׺���ʽ��ֵ����OPTR��OPND�ֱ�Ϊ�����ջ��������ջ
float Val_Exp(char* exp) {
	SqStack<char>OP(20);
	SqStack<float> OD(20);
	char theta;
	float a, b, d;
	//����ɼ��̽��յ��ַ�
	char c, x;
	//��Ÿ������ַ���
	char z[6];
	int i;
	//=�Ǳ��ʽ�����ı�־
	OP.Push('=');
	c = *exp++;
	x = OP.GetTop();
	while (c!='='||x!='=')
	{
		//��7�������֮һ
		if (In(c)) {
			switch (Precede(x,c))
			{
				//ջ��Ԫ������Ȩ��
			case '<':
				OP.Push(c);
				c = *exp++;
				break;
				//�����Ų�������һ���ַ�
			case '=':
				x = OP.Pop();
				c = *exp++;
				break;
				//��ջ������������ջ
			case '>':
				theta = OP.Pop();
				b = OP.Pop();
				a = OD.Pop();
				OD.Push(Operate(a, theta, b));

			default:
				break;
			}
		}
		//c�ǲ�����
		else if (c >= '0' && c <= '9' || c == '.') {
			i = 0;
			do {
				z[i] = c;
				i++;
				c = *exp++;
			} while (c >= '0' && c <= '9' || c == '.');
			z[i] = '\0';
			//���ַ�������תΪ�����ʹ���d
			d = atof(z);
			OD.Push(d);
		}
		//c�ǷǷ��ַ�
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

//����׺ʽ���׺ʽ
void CreatePostExp(char* exp, char*& postexp) {
	char c, x;
	int i = 0;
	SqStack<char>OP(20);
	//=�Ǳ��ʽ�����ı�־
	OP.Push('=');
	cout << "exp:" << exp << endl;
	c = *exp++;
	while (c)
	{
		if ((c >= '0' && c <= '9') || c == '.') {
			postexp[i++] = c;
			c = *exp++;
		}
		//��7�������֮һ
		if (In(c)) {
			postexp[i++] = ' ';
			x = OP.GetTop();
			switch (Precede(x, c))
			{
			case '<':
				//ջ��Ԫ������Ȩ��
				OP.Push(c);
				c = *exp++;
				break;
			case '=':
				//�����Ų�������һ���ַ�
				x = OP.Pop();
				c = *exp++;
				break;
			case '>':
				//�������ջ���
				postexp[i++] = OP.Pop();
				break;
			default:
				break;
			}
		}
		postexp[i] = '\0';
	}
	cout << "��׺���ʽΪ��" << postexp << endl;
}

//��׺���ʽ��ֵ
float Val_PostExp(char* postexp) {
	int i;
	char z[6];
	float v = 0, d = 0, a, b;
	char c;
	SqStack<float>OD(20);
	c = *postexp++;
	while (c!='\0')
	{
		//Ϊ������
		if ((c >= '0' && c <= '9') || c == '.') {
			i = 0;
			do {
				z[i++] = c;
				c = *postexp++;
			} while (c >= '0' && c <= '9' || c == '.');
			z[i] = '\0';
			//���ַ�������תΪ�����ʹ���d
			d = atof(z);
			OD.Push(d);
		}
		//cΪ�����
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
		cout << "1-�������ʽ\n";
		cout << "2-���ʽ��ֵ\n";
		cout << "3-���׺���ʽ\n";
		cout << "4-��׺���ʽ��ֵ\n";
		cout << "5-��ʾ���ʽ\n";
		cout << "6-�˳�\n";
		cout << "Enter choice:";
		cin >> choice;
		switch (choice)
		{
			//�������ʽ
		case 1:
			cout << "��������ʽ����=����" << endl;
			cin >> exp;
			cin.get(pause);
			system("pause");
			break;
			//���ʽ��ֵ
		case 2:
			v1 = Val_Exp(exp);
			cout << exp;
			cout << v1 << endl;
			cin.get(pause);
			system("pause");
			break;
			//���׺���ʽ
		case 3:
			CreatePostExp(exp, postexp);
			cin.get(pause);
			system("pause");
			break;
			//��׺���ʽ��ֵ
		case 4:
			v1 = Val_PostExp(postexp);
			cout << postexp << "=" << v1 << endl;
			cin.get(pause);
			system("pause");
			break;
			//��ʾ���ʽ
		case 5:
			cout << endl;
			cout << "�Ѵ����ı��ʽΪ��";
			cout << exp << endl;
			if (strlen(postexp)) {
				cout << "��׺���ʽΪ��";
				cout << postexp << endl;
			}
			cin.get(pause);
			system("pause");
			break;
			//�˳�
		case 6:
			break;
			//ѡ�񲻺���
		default:
			cout << "Invalid choice\n";
			break;
		}
	} while (choice != 6);

	return 0;
}