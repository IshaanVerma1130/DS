#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;
};

Node* newNode(int data) {
	Node* node = new Node;
	node->data = data;
	node->right = node->left = NULL;
	return node;
}

Node* insertNodes(int arr[], Node* root, int i, int n) {
	if (i < n) {
		Node* temp = newNode(arr[i]);
		root = temp;

		root->left = insertNodes(arr, root->left, 2 * i + 1, n);
		root->right = insertNodes(arr, root->right, 2 * i + 2, n);
	}

	return root;
}

int maxDepth(Node* root) {
	if (root->right == NULL && root->left == NULL) {
		return 1;
	}

	int l = maxDepth(root->left);
	int r = maxDepth(root->right);
	return (1 + ((l > r) ? l : r));
}

int minDepth(Node* root) {
	if (root->right == NULL && root->left == NULL) {
		return 1;
	}

	else {
		int l = minDepth(root->left);
		int r = minDepth(root->right);
		return (1 + ((l > r) ? r : l));
	}
}

void traverse(Node* root) {
	if (root == NULL) {
		return;
	}

	traverse(root->left);
	cout << root->data << " ";
	traverse(root->right);
}

int main() {
	int n = 10;
	// cin >> n;
	int arr[n] = { 5, 4, 1, 6, 2, 8, 9, 3, 7, 11 };

	// for (int i = 0; i < n; i++)
	// {
	//     cin >> arr[i];
	// }

	Node* root = insertNodes(arr, root, 0, n);
	// cout << minDepth(root) << " " << maxDepth(root);
	traverse(root);
}
