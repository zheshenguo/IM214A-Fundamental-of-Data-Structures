#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(void)
{
	int num[4][5];
	int transpose[5][4];
	fstream data;
	
	data.open("Numbers.txt");

	if( !data.is_open() )
	{
		cout << "Failed to open file!\n";
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				data >> num[i][j];
			}
		}

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				transpose[j][i] = num[i][j];
			}
		}

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << transpose[i][j] << " ";
			}
			cout << "\n";
		}
	}

	system("PAUSE");

	return 0;
}
