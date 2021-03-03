#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;

	Node(int val) {
		data = val;
	}
};

struct DLL {
	Node* head{ NULL };

	void insert_at_front(int val) {
		Node* new_node = new Node(val);
		new_node->next = head;
		new_node->prev = NULL;

		if (head != NULL) {
			head->prev = new_node;
		}

		head = new_node;
	}

	void insert_at_end(int val) {
		Node* new_node = new Node(val);
		new_node->next = NULL;
		Node* temp = head;

		if (head == NULL) {
			new_node->prev = NULL;
			head = new_node;
			return;
		}

		while (temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = new_node;
		new_node->prev = temp;
	}

	void delete_node(int val) {
		Node* temp = head;

		if (temp != NULL && temp->data == val) {
			temp->next->prev = head;
			head = temp->next;
			delete temp;
			return;
		}

		while (temp->next != NULL && temp->data != val) {
			temp = temp->next;
		}

		if (temp->data != val) {
			cout << "Value " << val << " not found in linked list";
			return;
		}

		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
	}

	void traverse() {
		Node* temp = head;

		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main() {
	DLL dll;
	dll.insert_at_front(1);
	dll.insert_at_front(2);
	dll.insert_at_end(3);
	dll.insert_at_end(4);
	dll.traverse();
	dll.delete_node(3);
	dll.traverse();
	dll.delete_node(2);
	dll.traverse();
	dll.delete_node(2);
}
