#include<iostream>
#include<cstring>
using namespace std;

//BF算法
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

//得到next数组
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

//KMP算法
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


//主函数
int main() {
	cout << "*********************************************" << endl;
	cout << "*********************************************" << endl;
	cout << ">1.BF算法" << endl;
	cout << ">2.KMP算法" << endl;
	cout << ">0.退出" << endl;
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
			cout << "请输入文本字符串：" << endl;
			cin >> s1;
			cout << "请输入模式字符串：" << endl;
			cin >> t1;
			cout << "正在开始模式匹配！。。。" << endl;
			int temp1 = getIndex(s1, t1);
			if (temp1 != -1) {
				cout << "从第" << temp1 + 1 << "个元素开始，匹配成功!" << endl;
			}
			else
			{
				cout << "匹配失败！" << endl;
			}
			break;
		}
			
		case 2:
		{
			string s, t;
			cout << "请输入文本字符串：" << endl;
			cin >> s;
			cout << "请输入模式字符串：" << endl;
			cin >> t;
			cout << "正在开始模式匹配！。。。" << endl;
			int next[100] = {};
			getNext(t, next);

			int temp = getKmpIndex(s, t, next);
			if (temp != -1) {
				cout << "从第" << temp + 1 << "个元素开始，匹配成功!" << endl;
			}
			else
			{
				cout << "匹配失败！" << endl;
			}
			break;
			
		}
		case 0:
			cout << "走好，不送 :)" << endl;
			break;
		default:
			cout << "Oops！请重新选择." << endl;
			break;
		}
	} while (choice!=0);
	

	return 0;
}