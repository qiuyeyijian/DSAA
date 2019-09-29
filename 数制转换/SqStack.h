#pragma once
#include<iostream>
using namespace std;

template<class T>
class SqStack
{
public:
	SqStack();
	~SqStack();
	SqStack(int m);
	void Push(T x);
	T Pop();
	T GetTop();
	int StackEmpty();
	void ClearStack();
	void stacktop();
	void StackTranverse();
private:
	T* base;
	int top;
	int stacksize;

};

//构造函数，创建一空栈
template<class T>
SqStack<T>::SqStack(int m)
{
	base = new T[m];
	if (base == NULL) {
		cout << "栈创建失败，退出！" << endl;
		exit(1);
	}
	stacksize = m;
	top = -1;
}

//析构函数，销毁栈
template<class T>
SqStack<T>::~SqStack() {
	delete[] base;
	top = 0;
	stacksize = 0;
}

//入栈
template<class T>
void SqStack<T>::Push(T x) {
	if (top == stacksize - 1) {
		throw "栈满，无法入栈";
	}
	top++;
	base[top] = x;

}

//出栈
template<class T>
T SqStack<T>::Pop() {
	T x;
	if (top == -1)
		throw "栈空，不能出栈";
	x = base[top--];
	return x;
}

//获取栈顶元素
template<class T>
T SqStack<T>::GetTop() {
	if (top == -1)
		throw "栈空，栈顶无元素";
	return base[top];
}

//测栈空
template<class T>
int SqStack<T>::StackEmpty() {
	if (top == -1)
		return 0;
	else
		return 1;
}

//清空栈
template<class T>
void SqStack<T>::ClearStack() {
	top = -1;
}

//返回栈顶指针
template<class T>
void SqStack<T>::stacktop() {
	cout << "栈顶 top=" << top;
	cout << endl;
}

//输出栈中元素
template<class T>
void SqStack<T>::StackTranverse() {
	int i = top;
	while (i>=0)
	{
		cout << base[i--] << '\t';
	}
	cout << endl;
}