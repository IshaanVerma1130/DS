#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;

	Node(int val) {
		data = val;
	}
};

struct LinkedList {
	Node* head;

	LinkedList() {
		head = NULL;
	}

	void insert_at_start(int val) {
		Node* new_node = new Node(val);
		new_node->next = head;
		head = new_node;
	}

	void insert_at_end(int val) {
		Node* new_node = new Node(val);
		new_node->next = NULL;

		if (head == NULL) {
			head = new_node;
			return;
		}

		Node* temp = head;
		while (temp->next) {
			temp = temp->next;
		}

		temp->next = new_node;
	}

	void delete_node(int val) {
		Node* temp = head;
		Node* prev = NULL;

		if (temp != NULL && temp->data == val) {
			head = temp->next;
			delete temp;
			return;
		}

		while (temp != NULL && temp->data != val) {
			prev = temp;
			temp = temp->next;
		}

		if (temp == NULL) {
			cout << "Value" << val << " not found in linked list";
			return;
		}

		prev->next = temp->next;
		delete temp;
	}

	void traverse() {
		Node* temp = head;

		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
};

int main() {

}
