#include <iostream>
using namespace std;

class TwoStack
{
private:

	int top1;
	int top2;
	int size;
	int* arr;

public:

	TwoStack(int n) {
		size = n;
		arr = new int[size];
		top1 = -1;
		top2 = size;

		for (int i = 0; i < top2; i++) {
			arr[i] = 0;
		}

		for (int i = top2; i < size; i++) {
			arr[i] = 0;
		}
	}

	void push1(int n) {
		if (top1 < top2 - 1) {
			top1++;
			arr[top1] = n;
		}

		else {
			cout << "Overflow from Stack 1";
		}
	}

	void push2(int n) {
		if (top1 < top2 - 1) {
			top2--;
			arr[top2] = n;
		}

		else {
			cout << "Overflow from Stack 2";
		}

	}

	int pop1() {
		if (top1 > -1) {
			top1--;
			return arr[top1 + 1];
		}

		else {
			cout << "Stack one is empty";
		}
	}

	int pop2() {
		if (top2 < size) {
			top2++;
			return arr[top2 - 1];
		}

		else {
			cout << "Stack two is empty";
		}
	}

	void show1() {
		if (top1 > -1) {
			cout << "Top of stack one -> ";
			for (int i = top1; i > -1; i--) {
				cout << arr[i] << " ";
			}
			cout << endl;
		}

		else {
			cout << "Stack one is empty";
		}
	}

	void show2() {
		if (top2 < size) {
			cout << "Top of stack two -> ";
			for (int i = top2; i < size; i++) {
				cout << arr[i] << " ";
			}
			cout << endl;
		}

		else {
			cout << "Stack two is empty";
		}
	}

	bool isEmpty() {
		if (top1 < -1 && top2 > size - 1) {
			return true;
		}

		else
			return false;
	}
};

int main() {
	TwoStack stack(100);
	stack.push1(78);
	stack.push1(67);
	stack.push1(56);
	stack.push1(45);
	stack.push1(34);

	stack.push2(78);
	stack.push2(67);
	stack.push2(56);
	stack.push2(45);
	stack.push2(34);

	stack.show1();
	stack.show2();
}
