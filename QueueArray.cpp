#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
	int front, rear, capacity;
	int* queue;

	Queue(int n) {
		front = rear = -1;
		capacity = n;
		queue = new int[capacity];
	}

	void enQueue(int n) {
		if (isFull()) {
			cout << "The queue is full";
			return;
		}

		else if (isEmpty()) {
			front++;
			rear++;
			queue[rear] = n;
		}

		else {
			rear++;
			queue[rear] = n;
		}

		return;
	}

	int deQueue() {
		if (isEmpty()) {
			cout << "The queue is empty";
			return 0;
		}

		else if (front == rear) {
			int x = queue[front];
			front = rear = -1;
			return x;
		}

		else {
			int x = queue[front];

			for (int i = 0; i < rear; i++) {
				queue[i] = queue[i + 1];
			}

			rear--;
			return x;
		}
	}

	int size() {
		if (isEmpty()) {
			cout << "Queue Is Empty";
			return 0;
		}

		else {
			return rear + 1;
		}
	}

	bool isFull() {
		if (rear == capacity - 1) {
			return true;
		}

		else {
			return false;
		}
	}

	bool isEmpty() {
		if (front == -1 && rear == -1) {
			return true;
		}

		else {
			return false;
		}
	}

	int peek() {
		return queue[front];
	}
};

int main() {
	Queue q(5);
	q.enQueue(1);
	cout << "Inserting 1" << endl;
	q.enQueue(2);
	cout << "Inserting 2" << endl;
	q.enQueue(3);
	cout << "Inserting 3" << endl;
	cout << "Front element is: " << q.peek() << endl;
	cout << "Removing " << q.deQueue() << endl;
	q.enQueue(4);
	cout << "Inserting 4" << endl;
	cout << "Queue size is " << q.size() << endl;
	cout << "Removing " << q.deQueue() << endl;
	cout << "Removing " << q.deQueue() << endl;
	cout << "Removing " << q.deQueue() << endl;
	q.size();
}
