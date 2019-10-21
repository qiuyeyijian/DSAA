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
		cout << "1-元素入栈\n";
		cout << "2-元素出栈\n";
		cout << "3-取栈顶元素\n";
		cout << "4-置栈空n";
		cout << "5-测栈空n";
		cout << "6-显示栈元素\n";
		cout << "7-显示栈顶指针\n";
		cout << "8-退出\n";
		cout << "Enter choice";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "请输入插入元素的值:" << endl;
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
				cout << "出栈元素为：" << e << endl;
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
				cout << "栈不空" << endl;
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
			s.stacktop();
			break;
		case 8:
			cout << "程序结束" << endl;
			break;

		default:
			break;
		}



	} while (choice != 8);



	return 0;
}