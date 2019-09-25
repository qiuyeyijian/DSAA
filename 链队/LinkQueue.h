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
	//Ԫ�����
	void EnQueue(T x);
	//�Ӷ�Ԫ�س���
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

//���캯��������һ�ն�
template<class T>
LinkQueue<T>::LinkQueue()
{
	front = new Node<T>;
	front->next = NULL;
	rear = front;
}

//�������������ٶ�
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

//���
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
//����
template<class T>
T LinkQueue<T>::DeQueue() {
	T x;
	Node<T>* p;
	if (rear == front)
		throw "����";
	p = front->next;
	x = p->data;
	front->next = p->next;
	if (p->next == NULL)
		rear = front;

	delete  p;
	return x;
}

//��ȡ��ͷԪ��
template<class T>
T LinkQueue<T>::GetHead() {
	Node<T>* p;
	if (front == rear)
		throw"�ӿգ��޶�ͷԪ��";
	p = front->next;
	return p->data;
}

//��ȡ��βԪ��
template<class T>
T LinkQueue<T>::GetLast() {
	if (front == rear)
		throw "�ӿգ��޶�βԪ��";
	return rear->data;
}

//��ն�
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

//��ӿ�
template<class T>
int LinkQueue<T>::QueueEmpty() {
	if (front == rear)
		return 1;
	else
	{
		return 0;
	}
}

//�Ӷ��׵���β�������������Ԫ��
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

