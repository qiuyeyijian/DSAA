#include<iostream>
using namespace std;


//创建顺序表类
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


//默认构造函数
SqList::SqList() {

}

//初始化顺序表
SqList::SqList(int m) {
	elem = new int[10];
	if (!elem)
		throw "内存分配失败";
	length = 0;
	listsize = 10;
}

//销毁顺序表
SqList::~SqList() {
	delete[]elem;
	length = 0;
	listsize = 0;
}

//创建顺序表
void SqList::CreatList(int n) {
	elem = new int[10];
	if (!elem)
		throw "内存分配失败";
	for (int i = 0; i < n; i++) {
		cout << "请输入第" << i << "个元素" << endl;
		cin >> elem[i];
	}
	length = n;
	listsize = 10;
}


//顺序表插入
void SqList::Insert(int i, int e) {
	if (length >= listsize)
		throw "上溢";
	if (i<1 || i>length + 1)
		throw "内存申请失败";
	for (int j = length; j >= i; j--)
		elem[j] = elem[j - 1];
	elem[i - 1] = e;
	length++;

}


//删除顺序表中元素
int SqList::Delete(int i) {
	if (length == 0)
		throw "下溢";
	if (i<1 || i>length)
		throw "内存申请失败";
	int e = elem[i - 1];
	for (int j = i; j < length; j++)
		elem[j - 1] = elem[j];
	length--;
	return e;
}


//顺序表按值查找
int SqList::Locate(int e) {
	for (int i = 0; i < length; i++)
		if (elem[i] == e)
			return i + 1;
		else
			return 0;

}


//输出表元素
void SqList::ListDisp() {
	for (int i = 0; i < length; i++) {
		cout << elem[i] << ',';
	}
	cout << endl;
}

//清空表
void SqList::Clear() {
	delete[]elem;
	length = 0;
	listsize = 0;
}
//主函数
int main() {
	//SqList(5);
	SqList t;
	cout << "删除线性表第三个元素" << endl;
	t.CreatList(5);
	cout << "删除之前为：" << endl;
	t.ListDisp();
	t.Delete(3);
	cout << "删除之后为：" << endl;
	t.ListDisp();
	t.Clear();

	cout << "在线性表第四个元素后面插入元素20" << endl;
	t.CreatList(5);
	cout << "插入之前为：" << endl;
	t.ListDisp();
	t.Insert(5, 20);
	cout << "插入之后为：" << endl;
	t.ListDisp();

	return 0;
}