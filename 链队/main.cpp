#include<iostream>
#include<process.h>
#include<stdio.h>
#include<Windows.h>
#include"LinkQueue.h"
using namespace std;

char pause;

int main() {

	int e;
	LinkQueue<int>q;
	system("cls");
	int choice;

	do {
		cout << "1-���\n";
		cout << "2-����\n";
		cout << "3-ȡ��ͷԪ��\n";
		cout << "4-ȡ��βԪ��\n";
		cout << "5-�öӿ�\n";
		cout << "6-��ӿ�\n";
		cout << "7-�����Ԫ��\n";
		cout << "8-�˳�\n";
		cout << "Enter choice";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "���������Ԫ�ص�ֵ��";
			cin >> e;
			cout << endl;
			q.EnQueue(e);
			cin.get(pause);
			system("pause");
			break;
		case 2:
			try
			{
				e = q.DeQueue();
				cout << "����Ԫ��Ϊ:" << e << endl;
			}
			catch (char* err)
			{
				cout << err << endl;
			}
			cin.get(pause);
			system("pause");
			break;
		case 3:
			try
			{
				e = q.GetHead();
				cout << "��ͷԪ��Ϊ��" << e << endl;
			}
			catch (char* err)
			{
				cout << err << endl;
			}
			cin.get(pause);
			system("pause");
			break;
		case 4:
			try
			{
				e = q.GetLast();
				cout << "��βԪ��Ϊ��" << e << endl;
			}
			catch (char* err)
			{
				cout << err << endl;
			}
			cin.get(pause);
			system("pause");
			break;
		case 5:
			q.ClearQueue();
			cin.get(pause);
			system("pause");
			break;
		case 6:
			if (q.QueueEmpty())
				cout << "�ӿ�"<<endl;
			else
			{
				cout << "�Ӳ���" << endl;
			}
			cin.get(pause);
			system("pause");
			break;
		case 7:
			q.QueueTranverse();
			cin.get(pause);
			system("pause");
			break;
		case 8:
			return 0;
		default:
			cout << "invalid choice\n" << endl;
			break;
		}

	} while (choice != 0);


	return 0;
}
