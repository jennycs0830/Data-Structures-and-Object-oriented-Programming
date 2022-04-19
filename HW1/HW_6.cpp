#include <iostream>
#include <cstdlib>
using namespace std;
#define SIZE 10
 
template <class X>
class Bag
{
    X *arr;         
    int capacity;  
    int front;      
    int rear;       
    int count;      
public:
    Bag(int size = SIZE); 
    void dequeue();
    void enqueue(X x);
    X peek();
    int size();
    bool isEmpty();
    bool isFull();
};
template <class X>
Bag<X>::Bag(int size)
{
    arr = new X[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}
template <class X>
void Bag<X>::dequeue()
{
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    cout << "Removing " << arr[front] << endl;
    front = (front + 1) % capacity;
    count--;
}
template <class X>
void Bag<X>::enqueue(X item)
{
    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    };
 
    cout << "Inserting " << item << endl;
 
    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}
template <class X>
X Bag<X>::peek()
{
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}
template <class X>
int Bag<X>::size() {
    return count;
}
template <class X>
bool Bag<X>::isEmpty() {
    return (size() == 0);
}
template <class X>
bool Bag<X>::isFull() {
    return (size() == capacity);
}
int main()
{
    Bag<string> q(4);
    q.enqueue("a");
    q.enqueue("b");
    q.enqueue("c");
    cout << "The front element is " << q.peek() << endl;
    q.dequeue();
    q.enqueue("d");
    cout << "The queue size is " << q.size() << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    if (q.isEmpty()) {
        cout << "The queue is empty\n";
    }
    else {
        cout << "The queue is not empty\n";
    }
    return 0;
}
