#include <iostream>

using namespace std;
int main()
{
	int n;
	cin >> n;
	int m = n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (i == j)
			{
				a[i][j] = 0;
			}
			else {
				a[i][j] = 0 + rand() % 2;
				a[j][i] = a[i][j];
			}
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
}