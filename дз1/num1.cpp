#include <iostream>
#include <stdio.h>

using namespace std;

void find_num(char** st, int num, int len)
{
	for (int i = 0; i < num; i++)
	{
		if (strlen(st[i]) == len)
		{
			cout << st[i] << endl;
		}
	}
}

void sorting(char** st, int num)
{
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = num - 2; j >= i; j--)
		{
			if (strlen(st[j]) > strlen(st[j + 1]))
			{
				char* c = st[j];
				st[j] = st[j + 1];
				st[j + 1] = c;
			}
			else if (strlen(st[j]) == strlen(st[j + 1]))
			{
				if (strcmp(st[j], st[j + 1])>0)
				{
					char* c = st[j];
					st[j] = st[j + 1];
					st[j + 1] = c;
				}
			}
		}
	}
}

int main(void)
{
	setlocale(LC_ALL, "ru");
	int n;
	cout << "Введите количество слов(до 20): "; cin >> n;
	char** a = new char*[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new char[80];
		cout << "Введите "<<i+1<<"-й элемент: "; cin >> a[i];
	}
	sorting(a, n);
	cout << "\nОтсортированный массив: \n";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
	int l;
	cout << "\nДлина искомой строки: "; cin >> l;
	cout << "Строки заданной длины:\n";
	find_num(a, n, l);
}
