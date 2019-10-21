#include<iostream>
using namespace std;


//����˳�����
class SqList {
public:
	SqList();
	SqList(int m);
	~SqList();
	void CreatList(int n);
	void Insert(int i, int e);
	int Delete(int i);
	int GetElem(int i);
	int Locate(int e);
	void Clear();
	int Empty();
	int Full();
	int Length();
	void ListDisp();
private:
	int *elem;
	int length;
	int listsize;
};


//Ĭ�Ϲ��캯��
SqList::SqList() {

}

//��ʼ��˳���
SqList::SqList(int m) {
	elem = new int[10];
	if (!elem)
		throw "�ڴ����ʧ��";
	length = 0;
	listsize = 10;
}

//����˳���
SqList::~SqList() {
	delete[]elem;
	length = 0;
	listsize = 0;
}

//����˳���
void SqList::CreatList(int n) {
	elem = new int[10];
	if (!elem)
		throw "�ڴ����ʧ��";
	for (int i = 0; i < n; i++) {
		cout << "�������" << i << "��Ԫ��" << endl;
		cin >> elem[i];
	}
	length = n;
	listsize = 10;
}


//˳������
void SqList::Insert(int i, int e) {
	if (length >= listsize)
		throw "����";
	if (i<1 || i>length + 1)
		throw "�ڴ�����ʧ��";
	for (int j = length; j >= i; j--)
		elem[j] = elem[j - 1];
	elem[i - 1] = e;
	length++;

}


//ɾ��˳�����Ԫ��
int SqList::Delete(int i) {
	if (length == 0)
		throw "����";
	if (i<1 || i>length)
		throw "�ڴ�����ʧ��";
	int e = elem[i - 1];
	for (int j = i; j < length; j++)
		elem[j - 1] = elem[j];
	length--;
	return e;
}


//˳���ֵ����
int SqList::Locate(int e) {
	for (int i = 0; i < length; i++)
		if (elem[i] == e)
			return i + 1;
		else
			return 0;

}


//�����Ԫ��
void SqList::ListDisp() {
	for (int i = 0; i < length; i++) {
		cout << elem[i] << ',';
	}
	cout << endl;
}

//��ձ�
void SqList::Clear() {
	delete[]elem;
	length = 0;
	listsize = 0;
}
//������
int main() {
	//SqList(5);
	SqList t;
	cout << "ɾ�����Ա������Ԫ��" << endl;
	t.CreatList(5);
	cout << "ɾ��֮ǰΪ��" << endl;
	t.ListDisp();
	t.Delete(3);
	cout << "ɾ��֮��Ϊ��" << endl;
	t.ListDisp();
	t.Clear();

	cout << "�����Ա���ĸ�Ԫ�غ������Ԫ��20" << endl;
	t.CreatList(5);
	cout << "����֮ǰΪ��" << endl;
	t.ListDisp();
	t.Insert(5, 20);
	cout << "����֮��Ϊ��" << endl;
	t.ListDisp();

	return 0;
}