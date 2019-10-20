#pragma once

#include<iostream>
using namespace std;

template<class T>
struct Node
{
	T data;
	Node* next;
};

template<class T>
class LinkList
{
public:
	LinkList();
	~LinkList();
	void CreateList(int n);
	void Insert(int i, T e);
	T Delete(int i);
	T GetElem(int i);
	int Locate(T e);
	T prior(T e);
	int Empty();
	int Length();
	void ListDisplay();

private:
	Node<T>* Head;
};

//构造函数，创建空链表
template<class T>
LinkList<T>::LinkList() {
	Head = new Node<T>;
	Head->next = NULL;
}

//析构函数，释放链表
template<class T>
LinkList<T>::~LinkList() {
	Node<T>* p;
	while (Head)
	{
		p = Head;
		Head = Head->next;
		delete p;
	}
	Head = NULL;
}

//尾插法
template<class T>
void LinkList<T>::CreateList(int n) {
	Node<T>* p, * s;
	p = Head;
	cout << "请依次输入元素值" << endl;
	for (int i = 1; i <= n; i++) {
		s = new Node<T>;
		cout << "请输入第" << i << "个元素的值:" << endl;
		cin >> s->data;
		s->next = p->next;
		p->next = s;
		p = s;
	}
}

//在指定位置插入元素
template<class T>
void LinkList<T>::Insert(int i, T e) {
	int j = 0;
	Node<T>* p;
	p = Head;
	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
		throw "位置异常";
	else
	{
		Node<T>* s;
		s = new Node<T>;
		s->data = e;
		s->next = p->next;
		p->next = s;
	}
}

//删除指定位置的元素
template<class T>
T LinkList<T>::Delete(int i) {
	T x;
	Node<T>* p, * q;
	p = Head;
	int j = 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1)
		throw "位置异常";
	else
	{
		q = p->next;
		p->next = q->next;
		x = q->data;
		delete q;
		return x;
	}
}

//按元素值查找，找到，返回元素在表中的的位序，否则返回0
template<class T>
int LinkList<T>::Locate(T e) {
	int j = 1;
	Node<T>* p;
	p = Head->next;
	while (p && p->data != e)
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
		return 0;
	else
	{
		return j;
	}
}

//获取第i 个元素的值
template<class T>
T LinkList<T>::GetElem(int i) {
	Node<T>* p;
	p = Head->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		throw "位置异常";
	else
	{
		return p->data;
	}
}

//测表空
template<class T>
int LinkList<T>::Empty() {
	if (Head->next == NULL) {
		return 1;
	}
	else
	{
		return 0;
	}
}

//返回元素前驱
template<class T>
T LinkList<T>::prior(T e) {
	Node<T>* p, * q;
	p = Head;
	q = p->next;
	while (q && q->data != e) {
		p = q;
		q = q->next;
	}
	if (p == Head)
		throw "首元素，无前驱";
	else if (q == NULL)
		throw "元素不存在";
	else
		return p->data;
}

//测表长
template<class T>
int LinkList<T>::Length() {
	int len = 0;
	Node<T>* p;
	p = Head;
	while (p->next) {
		len++;
		p = p->next;
	}
	return len;
}

//遍历显示链表
template<class T>
void LinkList<T>::ListDisplay() {
	Node<T>* p;
	p = Head->next;
	int i = 1;
	while (p)
	{
		cout << i << "\t";
		cout << p->data << endl;
		p = p->next;
		i++;
	}
}