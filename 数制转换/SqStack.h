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

//���캯��������һ��ջ
template<class T>
SqStack<T>::SqStack(int m)
{
	base = new T[m];
	if (base == NULL) {
		cout << "ջ����ʧ�ܣ��˳���" << endl;
		exit(1);
	}
	stacksize = m;
	top = -1;
}

//��������������ջ
template<class T>
SqStack<T>::~SqStack() {
	delete[] base;
	top = 0;
	stacksize = 0;
}

//��ջ
template<class T>
void SqStack<T>::Push(T x) {
	if (top == stacksize - 1) {
		throw "ջ�����޷���ջ";
	}
	top++;
	base[top] = x;

}

//��ջ
template<class T>
T SqStack<T>::Pop() {
	T x;
	if (top == -1)
		throw "ջ�գ����ܳ�ջ";
	x = base[top--];
	return x;
}

//��ȡջ��Ԫ��
template<class T>
T SqStack<T>::GetTop() {
	if (top == -1)
		throw "ջ�գ�ջ����Ԫ��";
	return base[top];
}

//��ջ��
template<class T>
int SqStack<T>::StackEmpty() {
	if (top == -1)
		return 0;
	else
		return 1;
}

//���ջ
template<class T>
void SqStack<T>::ClearStack() {
	top = -1;
}

//����ջ��ָ��
template<class T>
void SqStack<T>::stacktop() {
	cout << "ջ�� top=" << top;
	cout << endl;
}

//���ջ��Ԫ��
template<class T>
void SqStack<T>::StackTranverse() {
	int i = top;
	while (i>=0)
	{
		cout << base[i--] << '\t';
	}
	cout << endl;
}