#include<iostream>
#include "SqStack.h"
using namespace std;

//��ʮ������nת��Ϊm������
template<class T>
void convert(T n, T m) {
	T e;
	char c;
	SqStack<int> s(10);
	cout << "��Ҫת����ʮ������Ϊ��" << n << endl;
	while (n)
	{
		try {
			s.Push(n % m);
		}
		catch (char* err) {
			cout << err << endl;
		}
		n = n / m;
	}

	cout << "ת��Ϊ" << m << "������Ϊ��";
	while (s.StackEmpty()){
		try {
			e = s.Pop();
			if (e < 10)
				cout << e << '\t';
			else
			{
				c = 'A' + e - 10;
				cout << c << '\t';
			}
		}
		catch (char* err) {
			cout << err << endl;
		}
	}
	cout << endl;
}

int main() {
	int n, m;
	char ans;
	int flag = 1;
	while (flag)
	{
		cout << "������Ҫת����ʮ��������";
		cin >> n;
		cout << "������Ҫת��������:";
		cin >> m;
		convert(n, m);
		cout << "������(Y/N)?" << endl;
		cin >> ans;
		if (ans == 'Y' || ans == 'y')
			flag = 1;
		else
		{
			flag = 0;
			cout << "�������н�����Bye-Bye!" << endl;
		}
	}
}