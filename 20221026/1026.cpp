#include <iostream>
using namespace std;


class node {
public:
	int data;
	node* next;

	node(int num) {
		data = num;
		next = NULL;
	}

};
class linkedList {
public:
	node* first;

	linkedList() {
		first = NULL;
	}
	void insert(int num) {

		node* newNode = new node(num);

		//如果沒有第一個，將first指向要插入的node
		if (first == NULL) {
			first = newNode;
			return;
		}
		//如果要插入的數比第一格小，則將插入的node的下一個指向first、first指向要插入的node
		if (newNode->data < first->data) {
			newNode->next = first;
			first = newNode;

			return;
		}

		//設定要依序瀏覽的指標  current
		node* current = first;

		//依序瀏覽
		while (/*如果current還有下一個(next)*/current->next != NULL && current->next->data < newNode->data/*current的下一個的值比要插入的node小*/) {
			current = current->next;
		}


		//鏈接
		newNode->next = current->next;
		current->next= newNode;
	}
	void print() {
		if (!first) {
			cout << "The list is empty." << endl;
			return;
		}

		node* current = first;
		cout << "The ordered list : ";
		while (current) {
			cout << current->data << "-->";
			current = current->next;
		}
		cout << "NULL" << endl;
	}
};


int main()
{
	linkedList list1;
	int num[4] = { 9,4,5,1 };
	for (int i = 3; i > -1; i--) {
		list1.insert(num[i]);
	}

	list1.print();

}
