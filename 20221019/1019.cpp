#include <iostream>
using namespace std;
class queue {
  public:
	int* data;
	int capacity;
	int front, rear;
	queue() {
		capacity = 6;
		rear = capacity - 1;
		front = capacity - 1;
		data = new int[capacity];
		for (int i = 0; i < capacity; i++)
			data[i] = NULL;
	}
	bool isFull() {
		return((rear + 1) % capacity == front);
	}
	bool isEmpty() {
		return(front == rear);
	}
	void push(int x) {//使用isFull()
		if (!isFull()) {
			if (rear == capacity - 1) {
				rear = 0;
				data[rear] = x;
			}
			else {
				data[++rear] = x;
			}
		}
		else {
			cout << "Queue is full" << "\n";
		}
	}
	int pop() {//使用isEmpty()
		int temp = 0;
		if (!isEmpty()) {
			if (front == capacity - 1) {
				front = 0;
				temp = data[front];
				data[front] = NULL;
			}
			else {
				temp = data[++front];
				data[front] = NULL;
			}
		}
		else {
			cout << "Queue is empty" << "\n";
		}
		return data[front];
	}
	void print() {
		cout << "佇列現狀：" << endl;
		for (int i = 0; i < capacity; i++) {
			cout << i << "\t" << data[i];
			if (rear == i)
				cout << "<--rear  ";
			if (front == i)
				cout << "<--front";
			cout << endl;
		}
		cout << "front" << ":" << front << endl;
		cout << "rear" << ":" << rear << endl << endl;
	}
};
int main()
{
	int d[10] = { 3,89,1,784,59,32,48,5,404,80 };
	queue q;
	q.pop();
	cout << endl;
	for (int i = 0; i < 6; i++) {
		q.push(d[i]);
		q.print();
	}
	for (int i = 0; i < 3; i++) {
		q.pop();
		q.print();
	}
	for (int i = 6; i < 9; i++) {
		q.push(d[i]);
		q.print();
	}
}
