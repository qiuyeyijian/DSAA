#include<iostream>
#include "SqStack.h"
using namespace std;

//把十进制数n转换为m进制数
template<class T>
void convert(T n, T m) {
	T e;
	char c;
	SqStack<int> s(10);
	cout << "需要转换的十进制数为：" << n << endl;
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

	cout << "转换为" << m << "进制数为：";
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
		cout << "输入需要转换的十进制数：";
		cin >> n;
		cout << "输入需要转换的数制:";
		cin >> m;
		convert(n, m);
		cout << "继续吗(Y/N)?" << endl;
		cin >> ans;
		if (ans == 'Y' || ans == 'y')
			flag = 1;
		else
		{
			flag = 0;
			cout << "程序运行结束，Bye-Bye!" << endl;
		}
	}
}