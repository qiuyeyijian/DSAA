#include<iostream>
#include "LinkStack.h"
using namespace std;

char pause;

int main() {
	int choice;
	LinkStack<int>s;
	do
	{
		int n = 0;
		int sum = 1;
		cout << "1-��Ԫ�ؽ׳�\n";
		cout << "2-�˳�\n";
		cout << "Enter choice:";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "������Ҫ��׳˵�Ԫ�أ�";
			cin >> n;
			for (int i = 1; i <= n; i++) {
				s.Push(i);
			}
			while (s.StackEmpty())
			{
				sum *= s.Pop();
			}
			cout << "���Ϊ��" << sum << endl;
		case 2:
			break;
		default:
			cout << "Invaild choice" << endl;
			break;
		}

	} while (choice != 2);


	system("pause");
	return 0;
}