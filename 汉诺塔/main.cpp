#include<iostream>
using namespace std;
int co = 0;
void move(int n, char a, char b) {
	co++;
	cout << "第" << co << "次移动:\t" << "将" << a << "移动到" << b << endl;
}
void hanoi(int n, char a, char b, char c) {
	if (n == 1) {
		move(n, a, c);
	}
	else
	{
		hanoi(n - 1, a, c, b);
		move(n, a, c);
		hanoi(n - 1, b, a, c);
	}
}

int main() {
	int n = 0;
	int choice = 0;
	do
	{
		cout << "1-开始游戏\n";
		cout << "2-结束游戏\n";
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "请输入汉诺的层数：";
			cin >> n;
			hanoi(n, 'A', 'B', 'C');
			system("pause");
			break;
		case 2:
			cout << "游戏结束！" << endl;
			break;
		default:
			cout << "Invalid choice!\n";
			break;
		}

	} while (choice != 2);

	system("pause");
	return 0;
}