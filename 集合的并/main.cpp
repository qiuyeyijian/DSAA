#include<iostream>
#include "process.h"
#include "LinkList.h"
#include<windows.h>
typedef int T;
int main() {
	T e;
	LinkList<int> La, Lb;
	int la_len, lb_len;
	int i;
	cout << "������Ҫ����A�����е�Ԫ�ظ�����";
	cin >> la_len;
	cout << endl;
	La.CreateList(la_len);

	cout << "������Ҫ����B�����е�Ԫ�ظ�����";
	cin >> lb_len;
	cout << endl;
	Lb.CreateList(lb_len);

	cout << "La: " << endl;
	La.ListDisplay();

	cout << "Lb: " << endl;
	Lb.ListDisplay();
	cout << endl;

	for (i = 1; i <= lb_len; i++) {
		try {
			e = Lb.GetElem(i);
		}

		catch (char* err) {
			cout << err << endl;
		}
		if (!La.Locate(e)) {
			try {
				La.Insert(++la_len, e);
			}
			catch (char* err) {
				cout << err << endl;
			}
		}
	}
	cout << "union: " << endl;
	La.ListDisplay();
	cout << endl;

	system("pause");

	return 0;
}
