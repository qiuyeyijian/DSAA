#pragma once
#include<iostream>
#include<Windows.h>
using namespace std;

//链栈实现
template<class T>
struct Node
{
	T data;
	Node<T>* next;
};

template<class T>
class LinkStack
{
public:
	LinkStack();
	~LinkStack();
	void Push(T x);
	T Pop();
	T GetTop();
	int StackEmpty();
	void ClearStack();
	void StackTranverse();

private:
	Node<T>* top;
};

template<class T>
LinkStack<T>::LinkStack()
{
	top = NULL;
}

//析构函数销毁栈
template<class T>
LinkStack<T>::~LinkStack()
{
	Node<T>* q;
	while (top)
	{
		q = top;
		top = top->next;
		delete q;
	}
}

//入栈
template<class T>
void LinkStack<T>::Push(T x) {
	Node<T>* s;
	s = new Node<T>;
	s->data = x;
	s->next = top;
	top = s;
}

//出栈
template<class T>
T LinkStack<T>::Pop() {
	T x;
	Node<T>* p;
	if (top == NULL)
		throw "下溢";
	x = top->data;
	p = top;
	top = top->next;
	delete p;
	return x;
}

//获取栈顶元素
template<class T>
T LinkStack<T>::GetTop() {
	if (top == NULL)
		throw "栈空，栈顶无元素";
	return top->data;
}

//清空栈
template<class T>
void LinkStack<T>::ClearStack() {
	while (top)
	{
		Node<T>* q;
		q = top;
		top = top->next;
		delete q;

	}
}

//测栈空
template<class T>
int LinkStack<T>::StackEmpty() {
	if (top == NULL)
		return 0;
	else
	{
		return 1;
	}
}

//从栈顶起遍历输出栈元素
template<class T>
void LinkStack<T>::StackTranverse() {
	Node<T>* p;
	p = top;
	while (p)
	{
		cout << p->data << '\t';
		p = p->next;
	}
	cout << endl;
}
