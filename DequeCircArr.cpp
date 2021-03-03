#include <iostream>
using namespace std;

class Deque {
	int size;
	int* arr;
	int front;
	int rear;

	bool is_full() {
		return (front == 0 and rear == size - 1) || (front == rear + 1);
	}

	bool is_empty() {
		return front == -1;
	}

public:
	Deque(int capacity) {
		size = capacity;
		arr = new int[size];
		rear = 0;
		front = -1;
	}

	void insert_front(int val) {
		if (is_full()) {
			cout << "Deque is full!" << endl;
			return;
		}

		if (front == -1) {
			front = rear = 0;
		}

		else if (front == 0) {
			front = size - 1;
		}

		else {
			front -= 1;
		}

		arr[front] = val;
	}

	void insert_rear(int val) {
		if (is_full()) {
			cout << "Deque is full!" << endl;
			return;
		}

		else if (front == -1) {
			front = rear = 0;
		}

		else if (rear == size - 1) {
			rear = 0;
		}

		else {
			rear += 1;
		}

		arr[rear] = val;
	}

	void delete_front() {
		if (is_empty()) {
			cout << "Deque is empty!" << endl;
			return;
		}

		if (front == rear) {
			front = -1;
			// rear = -1;
		}

		else {
			if (front == size - 1) {
				front = 0;
			}

			else {
				front = front + 1;
			}
		}
	}

	void delete_rear() {
		if (is_empty()) {
			cout << "Deque is empty!" << endl;
			return;
		}

		if (front == rear) {
			front = -1;
			// rear = -1;
		}

		else if (rear == 0) {
			rear = size - 1;
		}

		else {
			rear -= 1;
		}
	}

	int get_front() {
		if (is_empty()) {
			cout << "Deque is empty!" << endl;
			return -1;
		}

		return arr[front];
	}

	int get_rear() {
		if (is_empty()) {
			cout << "Deque is empty!";
			return -1;
		}

		return arr[rear];
	}

	void print() {
		for (int i = 0; i < size; i++) {
			if (arr[i]) {
				cout << arr[i] << " ";
			}
			else {
				cout << "0" << " ";
			}
		}
	}
};

int main() {
	int cap = 5;
	Deque dq(cap);

	dq.insert_front(1);
	dq.insert_rear(2);
	dq.insert_front(3);
	dq.insert_rear(4);
	dq.insert_front(5);
	dq.insert_rear(6);
	dq.delete_front();
	dq.delete_rear();
	dq.delete_rear();
	dq.delete_front();

	cout << "Front: " << dq.get_front() << endl;
	cout << "Rear: " << dq.get_rear() << endl;
	dq.print();
	cout << endl;

	cout << dq.get_front() << " " << dq.get_rear();
}
