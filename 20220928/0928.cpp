#include <iostream>
#include <fstream>
using namespace std;

fstream file;

class sparse_matrix {
	const static int MAX = 32;
public:
	int** data;
	int row, col;
	int len = 0;

	//請解釋下面的函式(範例)
	//三行陣列的建構式
	sparse_matrix(int r, int c) {
		row = r;//原本陣列的列數
		col = c;//原本陣列的行數

		//宣告動態二維陣列，結果為data[32][3]
		data = new int* [MAX];
		for (int i = 0; i < MAX; i++)
			data[i] = new int[3];

		//用data的第0列存入，原陣列的列數、行數、非0的值的數量
		data[len][0] = r;
		data[len][1] = c;
		data[len][2] = len;

		//把預計存入data的列的位置往後推
		len++;
	}

	//請解釋下面的函式
	//三行陣列插入式
	void insert(int r, int c, int val) {
		//確認行、列是否在原始位置，若傳入之r與c大於原行與列則輸出Wrong entry
		if (r > row || c > col) {
			cout << "Wrong entry";
			return;
		}
		//將傳入的的行、列、值、是第幾個非整數，輸入進data陣列
		else {
			data[len][0] = r;
			data[len][1] = c;
			data[len][2] = val;
			data[0][2] = len;
			len++;
		}
	}

	//請解釋下面的函式
	//當 void_1 被執行時，僅將傳入的非零整數的列、行與值傳入insert函式
	void void_1(int row, int col, int arr[][12]) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (arr[i][j] != 0) {
					insert(i, j, arr[i][j]);
				}
			}
		}
	}

	void threeCol_plus(sparse_matrix a, sparse_matrix b) {

		//因為i,j不會只用在for迴圈，所以要事先宣告
		int i, j;

		//a、b都從第1列開始檢視，直到a、b其中一個到達data的列數的上限
		for (i = 1, j = 1;/*a條件式*/i < a.len &&/*b條件式*/j < b.len;) {

			//計算a第i列和b第j列的編號位置
			int pos_a = a.data[i][0] * a.data[0][1] + a.data[i][1];
			int pos_b = b.data[j][0] * b.data[0][1] + b.data[j][1];

			//如果a的編號位置比較前面，則插入a的第i列
			if (pos_a < pos_b) {
				insert(a.data[i][0], a.data[i][1], a.data[i][2]);
				i++;
			}

			//如果b的編號位置比較前面，則插入b的第j列
			else if (pos_a > pos_b) {
				insert(b.data[j][0], b.data[j][1], b.data[j][2]);
				j++;
			}

			/*如果a、b的編號位置相同且相加後不為0，
			則插入 a第i列的列、行，a+b的值*/
			else if (pos_a == pos_b) {

				//相加後不為0
				if ((a.data[i][2] + b.data[j][2]) != 0) {
					insert(a.data[i][0], a.data[i][1], a.data[i][2] + b.data[j][2]);
				}
				i++;
				j++;
			}
		}

		//將a中剩下的data全部逐列加入到新的三行陣列中
		while (i < a.len) {
			insert(a.data[i][0], a.data[i][1], a.data[i][2]);
			i++;
		}

		//將b中剩下的data全部逐列加入到新的三行陣列中
		while (j < b.len) {
			insert(b.data[j][0], b.data[j][1], b.data[j][2]);
			j++;
		}
	}

	void print()
	{
		cout << "Dimension: " << row << "x" << col;
		cout << "\nSparse Matrix: \n\tRow\tColumn\tValue\n";
		for (int i = 0; i < len; i++)
		{
			cout << i << "\t" << data[i][0] << "\t " << data[i][1]
				<< "\t " << data[i][2] << endl;

			if (i == 0)
				cout << endl;
		}
		cout << endl;
	}
};



int main()
{
	file.open("sparse_matrix.txt");
	int a[10][12], b[10][12];
	char judge;
	if (!file) {
		cout << "Failed to open file.\n";
		system("PAUSE");
		exit(1);
	}
	else {
		if (file >> judge, judge != 'A')
			exit(1);

		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 12; j++)
				file >> a[i][j];

		if (file >> judge, judge != 'B')
			exit(1);

		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 12; j++)
				file >> b[i][j];
	}

	sparse_matrix sparse_a(10, 12);
	sparse_a.void_1(sparse_a.row, sparse_a.col, a);
	cout << "Sparse Martix A:" << endl;
	sparse_a.print();

	sparse_matrix sparse_b(10, 12);
	sparse_b.void_1(sparse_b.row, sparse_b.col, b);
	cout << "Sparse Martix B:" << endl;
	sparse_b.print();

	sparse_matrix sparse_a_plus_b(sparse_a.row, sparse_a.col);
	sparse_a_plus_b.threeCol_plus(sparse_a, sparse_b);
	cout << "Sparse Martix A+B:" << endl;
	sparse_a_plus_b.print();
}