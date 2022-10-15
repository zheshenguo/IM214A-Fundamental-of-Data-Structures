# include <iostream>
# include <cstdlib>
using namespace std;

class Stack {
private:
	int top;
	int capacity;
	int* stack;

public:
	Stack() {
		top = -1;
		capacity = 5;
		stack = new int[capacity];
	}

	//請完成下方函式
	bool IsFull() {
		if(top == capacity-1){
			return true;
		}
		else{
			return false;
		}
	}

	//請完成下方函式
	bool IsEmpty() {
		if(top == -1){
			return true;
		}
		else{
			return false;
		}
	}

	//請完成下方函式 Pushed value:
	void Push(int x) {
		if(IsFull() == false){
			stack[++top] = x;
			cout << "Pushed Value : " << stack[top] << endl;
		}
		else{
			cout << "Stack is full." << endl;
		}
	}

	//請完成下方函式 Popped value:
	void Pop() {
		if(IsEmpty() == false){
			cout << "Popped Value : "<< stack[top--] << endl;
		}
		else{
			cout << "Stack is empty." << endl;
		}
	}

	void PrintStack() {
		cout << endl << "堆疊現狀：" << endl;
		for (int i = top; i > -1; i--)
			cout << i << "\t" << stack[i] << endl;
	}
};

int main()
{
	Stack s;

	s.Pop();
	s.Push(5);
	s.Push(23);
	s.Push(9);
	s.Push(18);
	s.Push(21);
	s.Push(102);
	s.Pop();
	s.Push(40);
	s.PrintStack();

}
