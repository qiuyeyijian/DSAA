#include<iostream>
using namespace std;

int main() {
	string s1, s2;
	cout << "请输入要拼接的第一个字符串：" << endl;
	cin >> s1;
	cout << "请输入要拼接的第二个字符串：" << endl;
	cin >> s2;
	cout << "拼接后的字符串为：" << endl;
	cout << s1 + s2 << endl;


	return 0;
}