#include<iostream>
using namespace std;
int co = 0;
void move(int n, char a, char b) {
	co++;
	cout << "��" << co << "���ƶ�:\t" << "��" << a << "�ƶ���" << b << endl;
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
		cout << "1-��ʼ��Ϸ\n";
		cout << "2-������Ϸ\n";
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "�����뺺ŵ�Ĳ�����";
			cin >> n;
			hanoi(n, 'A', 'B', 'C');
			system("pause");
			break;
		case 2:
			cout << "��Ϸ������" << endl;
			break;
		default:
			cout << "Invalid choice!\n";
			break;
		}

	} while (choice != 2);

	system("pause");
	return 0;
}