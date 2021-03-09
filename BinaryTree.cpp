#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left, * right;

	Node(int val) {
		left = NULL;
		right = NULL;
		data = val;
	}
};

struct BinaryTree
{
	Node* create_node(int val) {
		Node* new_node = new Node(val);
		return new_node;
	}

	void insert_value(Node** root, int val) {
		if (*root == NULL) {
			*root = create_node(val);
		}

		else if (val <= (*root)->data) {
			insert_value(&((*root)->left), val);
		}

		else {
			insert_value(&((*root)->right), val);
		}
	}

	bool search_value(Node** root, int val) {
		if (*root == NULL) {
			return false;
		}
		if ((*root)->data == val) {
			return true;
		}
		if (val < (*root)->data) {
			search_value(&((*root)->left), val);
		}
		else {
			search_value(&((*root)->right), val);
		}
	}

	// void delete_value(Node** root, int val) {

	// }
};

int main() {
	Node* root = NULL;
	BinaryTree bt;
	bt.insert_value(&root, 10);
}
