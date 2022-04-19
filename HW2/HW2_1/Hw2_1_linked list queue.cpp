#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct NodeQueue {
	int data;
	NodeQueue *next;
	NodeQueue() :data(0), next(0) {};
	NodeQueue(int x) :data(x), next(0) {};
};

class Queuelist {
private:
	int size;
	NodeQueue *front;
	NodeQueue *back;
public:
	Queuelist() :size(0), front(0), back(0) {};
	void Push(int data);
	void Pop();
	int getFront();
	int getBack();
	bool Isempty();
	int getSize();
};

void Queuelist::Push(int data)
{
	if (Isempty())
	{
		front = new NodeQueue(data);
		back = front;
		size++;
		return;
	}
	NodeQueue *newNode = new NodeQueue(data);
	back->next = newNode;
	back = newNode;
	size++;
	return;
}

void Queuelist::Pop()
{
	if (Isempty())
	{
		cout << "The queue is empty." << endl;
		return;
	}
	NodeQueue *Node_delete = new NodeQueue;
	Node_delete = front;
	front = front->next;
	delete Node_delete;
	Node_delete=0;
	size--;
	return;
}

int Queuelist::getFront()
{
	if (Isempty()) {
		cout << "The queue is empty." << endl;
		return -1;
	}
	return front->data;
}

int Queuelist::getBack()
{
	if (Isempty())
	{
		cout << "The queue is empty." << endl;
		return -1;
	}
	return back->data;
}

int Queuelist::getSize()
{
	return size;
}

bool Queuelist::Isempty()
{
	return ((front&&back) == 0);
}

int main()
{
	Queuelist test;
	cout << "Select the function you want:" << endl;
	while (1)
	{
		cout << "(1)Push  (2)Pop  (3)getFront  (4)getBack  (5)getSize" << endl;
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			int data;
			cout << "Push data:";
			cin >> data;
			test.Push(data);
			break;
		case 2:
			test.Pop();
			break;
		case 3:
			cout << "Front data:" << test.getFront() << endl;
			break;
		case 4:
			cout << "Back data:" << test.getBack() << endl;
			break;
		case 5:
			cout << "Size:" << test.getSize() << endl;
			break;
		}
	}
	return 0;
}