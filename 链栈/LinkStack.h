#pragma once
#include<iostream>
#include<Windows.h>
using namespace std;

//��ջʵ��
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

//������������ջ
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

//��ջ
template<class T>
void LinkStack<T>::Push(T x) {
	Node<T>* s;
	s = new Node<T>;
	s->data = x;
	s->next = top;
	top = s;
}

//��ջ
template<class T>
T LinkStack<T>::Pop() {
	T x;
	Node<T>* p;
	if (top == NULL)
		throw "����";
	x = top->data;
	p = top;
	top = top->next;
	delete p;
	return x;
}

//��ȡջ��Ԫ��
template<class T>
T LinkStack<T>::GetTop() {
	if (top == NULL)
		throw "ջ�գ�ջ����Ԫ��";
	return top->data;
}

//���ջ
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

//��ջ��
template<class T>
int LinkStack<T>::StackEmpty() {
	if (top == NULL)
		return 0;
	else
	{
		return 1;
	}
}

//��ջ����������ջԪ��
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
