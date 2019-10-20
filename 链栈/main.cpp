#include<iostream>
#include "LinkStack.h"
using namespace std;

char pause;

int main() {
	int e;
	LinkStack<int>s;
	system("cls");
	int choice;
	do
	{
		cout << "1-Ԫ����ջ\n";
		cout << "2-Ԫ�س�ջ\n";
		cout << "3-ȡջ��Ԫ��\n";
		cout << "4-��ջ��\n";
		cout << "5-��ջ��\n";
		cout << "6-���ջԪ��\n";
		cout << "7-�˳�\n";
		cout << "Enter choice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "���������Ԫ�ص�ֵ��";
			cin >> e;
			cout << endl;
			s.Push(e);
			cin.get(pause);
			system("pause");
			break;
		case 2:
			try {
				e = s.Pop();
				cout << "��ջԪ��Ϊ��" << e << endl;
			}
			catch (char* err) {
				cout << err << endl;
			}
			cin.get(pause);
			system("pause");
			break;
		case 3:
			try {
				e = s.GetTop();
				cout << "ջ��Ԫ��Ϊ��" << e << endl;
			}
			catch (char* err) {
				cout << err << endl;
			}
			cin.get(pause);
			system("pause");
			break;
		case 4:
			s.ClearStack();
			cin.get(pause);
			system("pause");
			break;
		case 5:
			if (s.StackEmpty()) {
				cout << "ջ����" << endl;
			}
			else
			{
				cout << "ջ��" << endl;
			}
			cin.get(pause);
			system("pause");
			break;
		case 6:
			s.StackTranverse();
			cin.get(pause);
			system("pause");
			break;
		case 7:
			break;

		default:
			cout << "Invaild choice!\n";
			break;
		}
	} while (choice != 7);

	system("pause");
	return 0;
}