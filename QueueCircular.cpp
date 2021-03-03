#include<iostream>
using namespace std;

struct CircQueue {
	int front, rear, size;
	int* items;

	CircQueue(int n) {
		items = new int[size];
		front = rear = -1;
	}

	bool isFull() {
		return (front == 0 && rear == size - 1) || (front == rear + 1);
	}

	bool isEmpty() {
		return front == -1;
	}

	void enqueue(int n) {
		if (isFull()) {
			cout << "Queue is full !";
		}

		else if (front == -1) {
			front = 0;
		}

		rear = (rear + 1) % size;
		items[rear] = n;
	}

	int dequeue() {
		if (isEmpty()) {
			cout << "Queue is empty !";
			return -1;
		}
		else {
			int x = items[front];

			if (front == rear) {
				front = rear = -1;
			}

			else {
				front = (front + 1) % size;
			}

			return x;
		}
	}

	void display() {
		if (isEmpty()) {
			cout << "Queue is empty !";
		}

		else {
			for (int i = front; i <= rear; i = (i + 1) % size) {
				cout << items[i] << " ";
			}
		}
	}
};

int main() {
	struct CircQueue cq(5);
	cq.enqueue(5);
	cq.enqueue(6);
	cq.display();
	cout << endl;
	cout << cq.dequeue() << endl;
	cq.display();
}
