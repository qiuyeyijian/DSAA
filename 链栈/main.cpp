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
		cout << "1-元素入栈\n";
		cout << "2-元素出栈\n";
		cout << "3-取栈顶元素\n";
		cout << "4-置栈空\n";
		cout << "5-测栈空\n";
		cout << "6-输出栈元素\n";
		cout << "7-退出\n";
		cout << "Enter choice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "请输入插入元素的值：";
			cin >> e;
			cout << endl;
			s.Push(e);
			cin.get(pause);
			system("pause");
			break;
		case 2:
			try {
				e = s.Pop();
				cout << "出栈元素为：" << e << endl;
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
				cout << "栈顶元素为：" << e << endl;
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
				cout << "栈不空" << endl;
			}
			else
			{
				cout << "栈空" << endl;
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