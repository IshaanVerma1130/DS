#include <iostream>
using namespace std;

class Node
{
public:
	int val;
	int height;
	Node* left;
	Node* right;

	Node() {
		left = right = NULL;
		val = 0;
		height = 0;
	}

	Node(int n) {
		left = right = NULL;
		val = n;
		height = 0;
	}
};

class BBT
{
private:
	Node* root;

	int height(Node* node) {
		return node == NULL ? -1 : node->height;
	}

	int max(int l, int r) {
		return l > r ? l : r;
	}

	Node* insert(int data, Node* node) {
		if (node == NULL) {
			node = new Node(data);
		}

		else if (data < node->val) {
			node->left = insert(data, node->left);

			if (height(node->left) - height(node->right) == 2) {
				if (data < node->left->val) {
					node = rotateWithLeftChild(node);
				}

				else {
					node = doubleWithLeftChild(node);
				}
			}
		}

		else if (data > node->val) {
			node->right = insert(data, node->right);

			if (height(node->right) - height(node->left) == 2) {
				if (data > node->right->val) {
					node = rotateWithRightChild(node);
				}

				else {
					node = doubleWithRightChild(node);
				}
			}
		}

		node->height = max(height(node->left), height(node->right)) + 1;
		return node;
	}

	Node* rotateWithLeftChild(Node* n2) {
		Node* n1 = n2->left;
		n2->left = n1->right;
		n1->right = n2;
		n2->height = max(height(n2->left), height(n2->right)) + 1;
		n1->height = max(height(n1->left), n2->height) + 1;
		return n1;
	}

	Node* rotateWithRightChild(Node* n1) {
		Node* n2 = n1->right;
		n1->right = n2->left;
		n2->left = n1;
		n1->height = max(height(n1->left), height(n1->left)) + 1;
		n2->height = max(height(n2->right), n1->height);
		return n2;
	}

	Node* doubleWithLeftChild(Node* n3) {
		n3->left = rotateWithRightChild(n3->left);
		return rotateWithLeftChild(n3);
	}

	Node* doubleWithRightChild(Node* n1) {
		n1->right = rotateWithLeftChild(n1->right);
		return rotateWithRightChild(n1);
	}

	int countNodes(Node* node) {
		if (node == NULL) {
			return 0;
		}

		else {
			int count = 1;
			count += countNodes(node->left);
			count += countNodes(node->right);
			return count;
		}
	}

	bool search(Node* node, int data) {
		bool found = false;

		while ((node != NULL) && !found) {
			int value = node->val;

			if (data < value) {
				node = node->left;
			}

			else if (data > value) {
				node = node->right;
			}

			else {
				found = true;
				break;
			}

			found = search(node, data);
		}

		return found;
	}

	void preorder(Node* node) {
		if (node != NULL) {
			cout << node->val << " ";
			preorder(node->left);
			preorder(node->right);
		}
	}

public:
	BBT() {
		root = NULL;
	}

	bool isEmpty() {
		return root == NULL;
	}

	void clear() {
		root = NULL;
	}

	void insert(int data) {
		root = insert(data, root);
	}

	int countNodes() {
		return countNodes(root);
	}

	bool search(int data) {
		return search(root, data);
	}

	void preorder() {
		preorder(root);
	}
};

int main() {
	int n;
	cin >> n;

	BBT tree;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		tree.insert(x);
	}

	tree.preorder();
}
