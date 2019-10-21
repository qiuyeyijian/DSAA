#include<iostream>
#include<Windows.h>
#include<stdio.h>
using namespace std;

#define Max 20
typedef struct {
	float coef;
	int exp;
}PolyArray[Max];

struct PolyNode
{
	float coef;
	int exp;
	PolyNode* next;
};

class Poly
{
public:
	Poly();
	~Poly();
	void Create(PolyArray a, int n);
	void Disp();
	void Sort();
	void Add(Poly LB);


private:
	PolyNode* head;
};

Poly::Poly()
{
	head = new PolyNode;
	head->next = NULL;
}

Poly::~Poly()
{
	PolyNode* p;
	while (head != NULL) {
		p = head;
		head = head->next;
		delete p;
	}
	head = NULL;
}

void Poly::Disp() {
	PolyNode* p;
	p = head->next;
	while (p!=NULL)
	{
		cout << p->coef << "x^" << p->exp << '\t';
		p = p->next;
	}
	cout << endl;
}

void Poly::Create(PolyArray a, int n) {
	PolyNode* s, * r;
	int i;
	r = head;
	for (i = 0; i < n; i++) {
		s = new PolyNode;
		s->coef = a[i].coef;
		s->exp = a[i].exp;
		s->next = NULL;
		r->next = s;
		r = s;
	}
}

void Poly::Sort() {
	PolyNode* p, * q, * r;
	p = head->next;
	if (p != NULL) {
		r = p->next;
		p->next = NULL;
		p = r;
		while (p!=NULL)
		{
			r = p->next;
			q = head;
			while (q->next!=NULL&& q->next->exp<p->exp)
			{
				q = q->next;
			}
			p->next = q->next;
			q->next = p;
			p = r;
		}
	}
}

void Poly::Add(Poly LB) {
	float sum;
	PolyNode* pa, * pb, * qa, * qb;
	pa = head;
	qa = pa->next;
	pb = LB.head;
	qb = pb->next;
	while (qa!=NULL&&qb!=NULL)
	{
		if (qa->exp < qb->exp) {
			pa = qa;
			qa = qa->next;
		}
		else if(qa->exp>qb->exp)
		{
			pb->next = qb->next;
			qb->next = qa;
			pa->next = qb;
			pa = qb;
			qb = pb->next;
		}
		else
		{
			sum = qa->coef + qb->coef;
			if (sum==0)
			{
				pa->next = qa->next;
				delete qa;
				qa = pa->next;
				pb->next = qb->next;
				delete qb;
				qb = pb->next;
			}
			else
			{
				qa->coef = sum;
				pa = qa;
				qa = qa->next;
				pb->next = qb->next;
				delete qb;
				qb = pb->next;
			}
		}
	}
	if (qb != NULL) {
		pa->next = qb;
	}
}

int main() {
	Poly LA, LB;
	PolyArray a = { {7.0,0},{3.0,1},{9.0,8},{5.0,16} };
	PolyArray b = { {8.0,1},{22,7},{-9.0,8} };
	LA.Create(a, 4);
	LB.Create(b, 3);
	cout << "原多项式A为：";
	LA.Disp();
	cout << "原多项式B为：";
	LB.Disp();

	LA.Sort();
	LB.Sort();

	cout << "有序多项式A为：";
	LA.Disp();
	cout << "有序多项式B为：";
	LB.Disp();
	LA.Add(LB);
	cout << "和多项式为：";
	LA.Disp();

	system("pause");
	return 0;
}