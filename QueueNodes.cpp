//ishaan verma
#include <bits/stdc++.h> 
using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int d) {
		data = d;
		next = NULL;
	}
};

struct Queue {
	Node* front, * rear;
	Queue() {
		front = rear = NULL;
	}

	void enQueue(int x) {

		// Create a new LL node 
		Node* temp = new Node(x);

		// If queue is empty, then 
		// new node is front and rear both 
		if (isEmpty()) {
			front = rear = temp;
			return;
		}

		// Add the new node at 
		// the end of queue and change rear 
		rear->next = temp;
		rear = temp;
	}

	// Function to remove 
	// a key from given queue q 
	int deQueue() {
		// If queue is empty, return NULL. 
		if (isEmpty())
			return 0;

		// Store previous front and 
		// move front one node ahead 
		Node* temp = front;
		front = front->next;

		// If front becomes NULL, then 
		// change rear also as NULL 
		if (front == NULL)
			rear = NULL;

		return temp->data;
	}

	bool isEmpty() {
		if (front == NULL)
			return true;
	}
};

int main() {

}
//ishaan verma
