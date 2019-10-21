#include<iostream>
#include<Windows.h>
#include "stdio.h"
#include "SqStack.h"

char pause;

int main() {
	int e;
	SqStack<int> s(20);
	system("cls");
	int choice = 0;
	do {
		cout << "1-Ԫ����ջ\n";
		cout << "2-Ԫ�س�ջ\n";
		cout << "3-ȡջ��Ԫ��\n";
		cout << "4-��ջ��n";
		cout << "5-��ջ��n";
		cout << "6-��ʾջԪ��\n";
		cout << "7-��ʾջ��ָ��\n";
		cout << "8-�˳�\n";
		cout << "Enter choice";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "���������Ԫ�ص�ֵ:" << endl;
			cin >> e;
			cout << endl;
			try{
				s.Push(e);
			}
			catch(char*err){
				cout << err << endl;
			}
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
				cout << "��ջԪ��Ϊ��" << e << endl;
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
			if (s.StackEmpty())
				cout << "ջ����" << endl;
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
			s.stacktop();
			break;
		case 8:
			cout << "�������" << endl;
			break;

		default:
			break;
		}



	} while (choice != 8);



	return 0;
}