//ishaan verma
#include <iostream>
using namespace std;

class Stack
{
public:

	int size;
	int* arr;
	int top = -1;

	Stack(int n) {
		size = n;
		arr = new int[size];
	}

	int Top() {
		return top + 1;
	}

	void push(int n) {
		if (top == size - 1) {
			cout << "Stack is full!" << endl;
		}
		else {
			top++;
			arr[top] = n;
		}
	}

	int pop() {
		if (top == -1) {
			cout << "Stack is empty!" << endl;
			return -1;
		}
		else {
			top--;
			return arr[top + 1];
		}
	}

	bool empty() {
		return top == -1;
	}

	void show() {
		if (top == -1) {
			cout << "Stack is empty!" << endl;
		}

		else {
			for (int i = 0; i <= top; i++) {
				cout << arr[i] << " ";
			}
		}
	}
};

int main() {
	Stack s(5);
	s.push(5);
	s.push(10);
	s.show();
	cout << s.Top();
}
//ishaan verma
