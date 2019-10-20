#include<iostream>
using namespace std;

template<class T>
class SqStack
{
public:
	SqStack();
	~SqStack();
	void Push(T x);
	T Pop();
	T GetTop();
	int StackEmpty();
	void ClearStack();
	void StackTop();
	void StackTranverse();

private:
	T* base;
	int top;
	int stacksize;
};
template<class T>
SqStack<T>::~SqStack() {
	delete[]base;
	top = -1;
	stacksize = 0;
}
//顺序栈初始化
SqStack<int>::SqStack()
{
	base = new int[5];
	if (base == NULL) {
		cout << "栈创建失败，退出！" << endl;
		exit(1);
	}
	stacksize = 5;
	top = *base = 0;
}

//顺序栈入栈
template<class T>
void SqStack<T>::Push(T x) {
	if (top == stacksize)
		throw "栈满，无法入栈";
	top++;
	base[top] = x;
}

//顺序栈出栈
template<class T>
T SqStack<T>::Pop() {
	if (top == 0)
		throw "栈空，不能出栈";
	T x = base[top--];
	return x;
}

//顺序栈取栈顶元素
template<class T>
T SqStack<T>::GetTop() {
	if (top == 0)
		throw "栈空，栈顶无元素";
	return base[top];
}


int main() {
	SqStack<int> t;
	cout << "创建一个新栈，请依次输入：1,2,3,4" << endl;
	for (int i = 0; i < 4; i++) {
		int temp = 0;
		cin >> temp;
		t.Push(temp);
	}
	cout << "栈顶元素为：" << t.GetTop();




	return 0;
}