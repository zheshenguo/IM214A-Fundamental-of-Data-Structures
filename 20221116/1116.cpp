#include<iostream>
#include<cstdlib>
#include<ctime>
#define capacity 10

using namespace std;
void BubbleSort_Ascending(int [],int []);
void BubbleSort_decending(int[], int[]);
void SelectionSort_Ascending(int[], int[]);
void SelectionSort_decending(int[], int[]);
void InsertionSort_Ascecding(int[], int[]);
void InsertionSort_decending(int[], int[]);
int main()
{
	srand(time(NULL));
	int int_arr[10], original_arr[10];
	cout << "Original Array:" << endl;
	for (int i = 0; i < capacity; i++) {
		original_arr[i] = rand() % 20 + 1;
		int_arr[i] = original_arr[i];
	}
	//for (int i = 0; i < 10; i++) {
	//	original_arr[i] = i+1;
	//	int_arr[i] = original_arr[i];
	//}
	for (int k = 0; k < 10; k++) {
		cout << int_arr[k] << '\t';
	}
	cout << endl;
	BubbleSort_Ascending(int_arr, original_arr);
	BubbleSort_decending(int_arr,  original_arr);
	SelectionSort_Ascending(int_arr,original_arr);
	SelectionSort_decending(int_arr, original_arr);
}
void BubbleSort_Ascending(int int_arr[], int original_arr[]) {
	cout << "BubbleSort(Ascending):" << endl;
	for (int i = 0; i < capacity - 1; i++) {
		for (int j = 0; j < capacity - 1 - i; j++) {
			if (int_arr[j] > int_arr[j + 1]) {
				int temp = int_arr[j];
				int_arr[j] = int_arr[j + 1];
				int_arr[j + 1] = temp;
			}
		}
		for (int k = 0; k < 10; k++) {
			cout << int_arr[k] << '\t';
		}
		cout << endl;
	}
	for (int i = 0; i < capacity; i++) {
		int_arr[i] = original_arr[i];
	}
}
void BubbleSort_decending(int int_arr[], int original_arr[]) {
	cout << "BubbleSort(Decending):" << endl;
	for (int i = 0; i < capacity - 1; i++) {
		for (int j = 0; j < capacity - 1 - i; j++) {
			if (int_arr[j] < int_arr[j + 1]) {
				int temp = int_arr[j];
				int_arr[j] = int_arr[j + 1];
				int_arr[j + 1] = temp;
			}
		}
		for (int k = 0; k < 10; k++) {
			cout << int_arr[k] << '\t';
		}
		cout << endl;
	}
	for (int i = 0; i < capacity; i++) {
		int_arr[i] = original_arr[i];
	}
	cout << endl;
}
void SelectionSort_Ascending(int int_arr[], int original_arr[]) {
	cout << "SelectionSort(Ascending):" << endl;
	for (int i = 0; i < capacity - 1; i++) {
		int min = i;
		for (int j = i + 1; j < capacity; j++) {
			if (int_arr[j] < int_arr[min]) {
				min = j;
			}
		}
		int temp = int_arr[min];
		int_arr[min] = int_arr[i];
		int_arr[i] = temp;
		for (int k = 0; k < 10; k++) {
			cout << int_arr[k] << '\t';
		}
		cout << endl;
	}
	for (int i = 0; i < capacity; i++) {
		int_arr[i] = original_arr[i];
	}
}
void SelectionSort_decending(int int_arr[], int original_arr[]) {
	cout << "SelectionSort(Decending):" << endl;
	for (int i = 0; i < capacity - 1; i++) {
		int max = i;
		for (int j = i + 1; j < capacity; j++) {
			if (int_arr[j] > int_arr[max]) {
				max = j;
			}
		}
		int temp = int_arr[max];
		int_arr[max] = int_arr[i];
		int_arr[i] = temp;
		for (int k = 0; k < 10; k++) {
			cout << int_arr[k] << '\t';
		}
		cout << endl;
	}
	for (int i = 0; i < capacity; i++) {
		int_arr[i] = original_arr[i];
	}
	cout << endl;
}
void InsertionSort_Ascecding(int int_arr[], int original_arr[]) {
	cout << "InsertionSort(Ascending):" << endl;
	for (int i = 1; i < capacity; i++) {
		int key = int_arr[i];
		int j = i - 1;
		while (key < int_arr[j] && j >= 0) {//===========
			int_arr[j + 1] = int_arr[j];
			j--;
		}
		int_arr[j + 1] = key;
		for (int k = 0; k < 10; k++) {
			cout << int_arr[k] << '\t';
		}
		cout << endl;
	}
	for (int i = 0; i < capacity; i++) {
		int_arr[i] = original_arr[i];
	}
}
void InsertionSort_decending(int int_arr[], int original_arr[]) {
	cout << "InsertionSort(Decending):" << endl;
	for (int i = 1; i < capacity; i++) {//==================================
		int key = int_arr[i];
		int j = i - 1;
		while (key > int_arr[j] && j >= 0) {//=============
			int_arr[j + 1] = int_arr[j];
			j--;
		}
		int_arr[j + 1] = key;
		for (int k = 0; k < 10; k++) {
			cout << int_arr[k] << '\t';
		}
		cout << endl;
	}
	for (int i = 0; i < capacity; i++) {
		int_arr[i] = original_arr[i];
	}
}