#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void sort(int*, int);

int main(void)
{
	srand((unsigned)time(NULL)); // makes use of the computer's internal clock to control the choice of the seed
	
	int a[7];

	for (int i = 0; i < 7; i++)
	{
		a[i] = rand() % 101 + 200; // generates a random number between 200 and 300
	}

	sort(a, 7);

	for (int i = 0; i < 7; i++)
	{
		cout << i << ". " << a[i] << "\n";
	}

	cout << "\n";

	system("PAUSE");
	return 0;
}


// arranges the array to an ascending order
void sort(int* m, int n)
{
	// implementation in bubble sort
    for (int i = 0; i < n - 1; i++)
    {
    	for (int j = 0; j < n - i - 1; j++)
        {
        	if (m[j] > m[j + 1])
            {
            	swap(m[j], m[j + 1]);
			}
		}
	}     
}
