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

/*取t中的第一個節點j，取s中的第一個節點k，比較J和k的數據，相等則k後移，否則j後移且判斷是否為空，是則break，
否則繼續比較j和k的數值，最後若k==NULL則為子集*/


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

}//p和q比較，p是主鍊

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