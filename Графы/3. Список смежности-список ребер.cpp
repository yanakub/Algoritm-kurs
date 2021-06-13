#include <iostream>

using namespace std;
int main()
{
	int  n = 8;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = 0;
		}
	}
	a[0][2] = 1;
	a[0][6] = 1;
	a[1][2] = 1;
	a[1][3] = 1;
	a[2][3] = 1;
	a[2][4] = 1;
	a[4][7] = 1;
	a[4][5] = 1;
	a[6][7] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[j][i] = a[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ".  |";
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "|";
		}
		cout << " (";
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 1)
			{
				cout << j + 1 << ",";
			}
		}
		cout << ")";
		cout << endl;
	}

	for (int i = 0; i < n; i++)
	{

		for (int j = i; j < n; j++)
		{
			if (a[i][j] == 1)
			{
				cout << "(" << i + 1 << "," << j + 1 << ")" << endl;;
			}
		}
	}
}