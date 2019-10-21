#pragma once

#include<iostream>
using namespace std;

template<class T>
struct Node
{
	T data;
	Node<T>* next;
};
template<class T>
class LinkQueue
{
public:
	LinkQueue();
	~LinkQueue();
	//元素入队
	void EnQueue(T x);
	//队顶元素出队
	T DeQueue();
	T GetHead();
	T GetLast();
	int QueueEmpty();
	void ClearQueue();
	void QueueTranverse();
private:
	Node<T>* front;
	Node<T>* rear;
};

//构造函数，创建一空队
template<class T>
LinkQueue<T>::LinkQueue()
{
	front = new Node<T>;
	front->next = NULL;
	rear = front;
}

//析构函数，销毁队
template<class T>
LinkQueue<T>::~LinkQueue()
{
	Node<T>* p;
	while (front != NULL)
	{
		p = front;
		front = front->next;
		delete p;
	}
}

//入队
template<class T>
void LinkQueue<T>::EnQueue(T x) {
	Node<T>* s;
	s = new Node<T>;
	s->data = x;
	s->next = rear->next;
	rear->next = s;
	rear = s;
	if (front->next == NULL)
		front->next = s;
}
//出队
template<class T>
T LinkQueue<T>::DeQueue() {
	T x;
	Node<T>* p;
	if (rear == front)
		throw "下溢";
	p = front->next;
	x = p->data;
	front->next = p->next;
	if (p->next == NULL)
		rear = front;

	delete  p;
	return x;
}

//获取队头元素
template<class T>
T LinkQueue<T>::GetHead() {
	Node<T>* p;
	if (front == rear)
		throw"队空，无队头元素";
	p = front->next;
	return p->data;
}

//获取队尾元素
template<class T>
T LinkQueue<T>::GetLast() {
	if (front == rear)
		throw "队空，无队尾元素";
	return rear->data;
}

//清空队
template<class T>
void LinkQueue<T>::ClearQueue() {
	Node<T>* p;
	p = front->next;
	while (p)
	{
		front->next = p->next;
		delete p;
		p = front->next;
	}
	rear = front;
}

//测队空
template<class T>
int LinkQueue<T>::QueueEmpty() {
	if (front == rear)
		return 1;
	else
	{
		return 0;
	}
}

//从队首到队尾，遍历输出队中元素
template<class T>
void LinkQueue<T>::QueueTranverse() {
	Node<T>* p;
	p = front->next;
	while (p)
	{
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}