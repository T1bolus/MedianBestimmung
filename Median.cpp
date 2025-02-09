#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

inline void vertausche(int &a, int &b)
{
	int swap = a;
	a = b;
	b = swap;
}

int spalte_auf(int *a, int n1, int n2)
{
	int tind = (n1 + n2) / 2;
	vertausche(a[tind], a[n1]);
	tind = n1;

	for (int i = n1 + 1; i <= n2; i++)
	{
		if (a[i] <= a[tind])
		{
			vertausche(a[i], a[tind + 1]);
			vertausche(a[tind], a[tind + 1]);
			tind++;
		}

	}
	return tind;
}

int finde_ktes(int *a, int n, int k)
{
	int n1 = 0, n2 = n;
	int tind;
	while (true)
	{
		tind = spalte_auf(a, n1, n2);
		tind = tind - n1 + 1;

		if (tind < k)
		{
			n1 = n1 + tind;
			k = k - tind;
		}
		else if (tind == k)
			return n1 - 1 + k;
		else
			n2 = n1 + tind - 2;
	}
}


int main()
{
	int zahl;
	int length;
	
	cout << "Filename: ";
	string filename;
	cin >> filename;

	ifstream f(filename);
	f >> length;
	int *a = new int[length + 1];

	unsigned int index = 0;
	while (!f.eof() && index <= length)
	{
		f >> zahl;
		a[index++] = zahl;
	}
	cout << "Eingelesen: " << index << endl;
	
	int ende, start = clock();
	int result = finde_ktes(a, length - 1, length/2 + 2);
	ende = ((clock() - start) * 1000) / CLOCKS_PER_SEC;

	cout << "Time to finished: " << ende << " ms"<<  endl;
	cout << "Result: " << result << endl;
	system("pause");
}
