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
//˳��ջ��ʼ��
SqStack<int>::SqStack()
{
	base = new int[5];
	if (base == NULL) {
		cout << "ջ����ʧ�ܣ��˳���" << endl;
		exit(1);
	}
	stacksize = 5;
	top = *base = 0;
}

//˳��ջ��ջ
template<class T>
void SqStack<T>::Push(T x) {
	if (top == stacksize)
		throw "ջ�����޷���ջ";
	top++;
	base[top] = x;
}

//˳��ջ��ջ
template<class T>
T SqStack<T>::Pop() {
	if (top == 0)
		throw "ջ�գ����ܳ�ջ";
	T x = base[top--];
	return x;
}

//˳��ջȡջ��Ԫ��
template<class T>
T SqStack<T>::GetTop() {
	if (top == 0)
		throw "ջ�գ�ջ����Ԫ��";
	return base[top];
}


int main() {
	SqStack<int> t;
	cout << "����һ����ջ�����������룺1,2,3,4" << endl;
	for (int i = 0; i < 4; i++) {
		int temp = 0;
		cin >> temp;
		t.Push(temp);
	}
	cout << "ջ��Ԫ��Ϊ��" << t.GetTop();




	return 0;
}