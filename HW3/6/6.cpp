#include<iostream>

using namespace std;

template <class T>

struct Node {

	T data;

	Node<T>* next;

};

template <class T>

class LinkList {

private:

	Node<T>* first;

public:

	LinkList();

	LinkList(int n, T a[]);

	int length();

	void print();

	Node<T>* pop();

};

template <class T>

LinkList<T>::LinkList() {

	first = new Node<T>;

	first->next = NULL;

}

template <class T>

/*��t�����Ĥ@�Ӹ`�Ij�A��s�����Ĥ@�Ӹ`�Ik�A���J�Mk���ƾڡA�۵��hk�Ჾ�A�_�hj�Ჾ�B�P�_�O�_���šA�O�hbreak�A
�_�h�~����j�Mk���ƭȡA�̫�Yk==NULL�h���l��*/


LinkList<T>::LinkList(int n, T a[]) {

	first = new Node<T>;

	first->next = NULL;

	for (int i = 0; i < n; i++)

	{

		Node<T>* s;

		s = new Node<T>;

		s->data = a[i];

		s->next = first->next;

		first->next = s;

	}

}

template <class T>

int LinkList<T>::length() {

	int count = 0;

	Node<T>* m;

	m = first->next;

	while (m != 0) {

		count++;

		m = m->next;

	}

	return count;

}

template <class T>

void LinkList<T>::print() {

	Node<T>* p;

	p = first->next;

	while (p != NULL) {

		cout << p->data;

		p = p->next;

	}

}

template <class T>

Node<T>* LinkList<T>::pop() {

	return first;

}

template <class T>

void panduan(LinkList<T> a, LinkList<T> b) {

	Node<T>* p;

	Node<T>* q;

	if (a.length() >= b.length()) {

		q = (a.pop())->next;

		p = (b.pop())->next;

	}

	else

	{

		q = (b.pop())->next;

		p = (a.pop())->next;

	}

	while (p != NULL) {

		if (p->data == q->data)

			p = p->next;

		else {

			q = q->next;

			if (q == NULL) {

				cout << "subset";

				break;

			}

		}

	}

	if (p == NULL)

		cout << "not subset";

}//p�Mq����Ap�O�D��

int main()

{

	int sets[n] ;
	int sett[r] ;
	int i = 0;

	LinkList set_t(r, sett),set_s(n, sets) ;

	// A.print();

	// cout<<endl;

	// B.print();

	 panduan (set_t,set_s); cout << endl;
	return 0;

}