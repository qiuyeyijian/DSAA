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
		cout << "1-入队\n";
		cout << "2-出队\n";
		cout << "3-取队头元素\n";
		cout << "4-取队尾元素\n";
		cout << "5-置队空\n";
		cout << "6-测队空\n";
		cout << "7-输出队元素\n";
		cout << "8-退出\n";
		cout << "Enter choice";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "请输入插入元素的值：";
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
				cout << "出队元素为:" << e << endl;
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
				cout << "队头元素为：" << e << endl;
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
				cout << "队尾元素为：" << e << endl;
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
				cout << "队空" << endl;
			else
			{
				cout << "队不空" << endl;
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