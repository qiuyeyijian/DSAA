#include<iostream>
#include<cstring>
using namespace std;

//BF�㷨
int getIndex(string s, string t) {
	int m = s.length();
	int n = t.length();
	int i=0, j = 0;
	while (i<m && j<n)
	{
		if (s[i] == t[j]) {
			++i;
			++j;

		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (i <= m && j >= n) {
		return i - j;
	}
	else
	{
		return -1;
	}
}

//�õ�next����
void  getNext(string t, int next[]) {
	int i = 1;
	int j = 0;
	next[0] = 0;
	while (i<(int)t.length())
	{
		if (t[i] == t[j]) {
			++j;
			++i;
			next[i] = j;
		}
		if (j == 0) {
			++i;
		}
		else
		{
			j = next[j - 1];
		}

	}
}

//KMP�㷨
int getKmpIndex(string s, string t, int next[]) {
	int i = 0;
	int j = 0;
	int s1 = s.length();
	int t1 = t.length();
	while (i<s1 && j<t1)
	{
		if (s[i] == t[j]) {
			++i;
			++j;
		}
		else if (j == 0) {
			++i;
		}
		else
		{
			j = next[j - 1];
		}
	}
	if (j == (int)t.length()) {
		return i - j;
	}
	else
	{
		return -1;
	}
}


//������
int main() {
	cout << "*********************************************" << endl;
	cout << "*********************************************" << endl;
	cout << ">1.BF�㷨" << endl;
	cout << ">2.KMP�㷨" << endl;
	cout << ">0.�˳�" << endl;
	cout << "*********************************************" << endl;
	cout << "*********************************************" << endl;
	cout << endl;
	int choice = 0;
	int temp = 0;
	do
	{	
		cout << "Enter choice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			string s1, t1;
			cout << "�������ı��ַ�����" << endl;
			cin >> s1;
			cout << "������ģʽ�ַ�����" << endl;
			cin >> t1;
			cout << "���ڿ�ʼģʽƥ�䣡������" << endl;
			int temp1 = getIndex(s1, t1);
			if (temp1 != -1) {
				cout << "�ӵ�" << temp1 + 1 << "��Ԫ�ؿ�ʼ��ƥ��ɹ�!" << endl;
			}
			else
			{
				cout << "ƥ��ʧ�ܣ�" << endl;
			}
			break;
		}
			
		case 2:
		{
			string s, t;
			cout << "�������ı��ַ�����" << endl;
			cin >> s;
			cout << "������ģʽ�ַ�����" << endl;
			cin >> t;
			cout << "���ڿ�ʼģʽƥ�䣡������" << endl;
			int next[100] = {};
			getNext(t, next);

			int temp = getKmpIndex(s, t, next);
			if (temp != -1) {
				cout << "�ӵ�" << temp + 1 << "��Ԫ�ؿ�ʼ��ƥ��ɹ�!" << endl;
			}
			else
			{
				cout << "ƥ��ʧ�ܣ�" << endl;
			}
			break;
			
		}
		case 0:
			cout << "�ߺã����� :)" << endl;
			break;
		default:
			cout << "Oops��������ѡ��." << endl;
			break;
		}
	} while (choice!=0);
	

	return 0;
}