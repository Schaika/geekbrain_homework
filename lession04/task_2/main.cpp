/*
Таймер вставлен для определения скорости работы и может быть вырезан без последствий.
Алгоритм:
Сортируем массив по возрастанию и сравниваем каждый элемент с его соседом слева. Если они равны, увеличиваем счетчик копий.

Для 10 000 000 элементов время работы примерно равно ~0.376. Release, 64bit.
*/


#include <vector>
#include <iostream>
#include <chrono>
#include "timer.h"

using namespace std;

void print(vector<int> &a) {
	cout << "The length is: " << a.size() << '\n';

	for (int i=0; i<static_cast<int>(a.size()); i++)
		cout << a[i] << ' ';

	cout << endl;
}


void quickSort(vector<int> &a,int start, int end)
{
		if (end>static_cast<int>(a.size())-1 || start<0) return;
	int i = start;
	int j = end;
	int pivot = a[(start+end)/2];
	int buffer;

	while (i <= j)
	{
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;
		if (i <= j)
		{
			buffer = a[i];
			a[i] = a[j];
			a[j] = buffer;
			i++;
			j--;
		}
	}
	if (j > start) quickSort(a,start, j);
	if (i < end) quickSort(a,i, end);
}

void quickSort(vector<int> &a){
		quickSort(a,0,static_cast<int>(a.size())-1);
	}

int count_copies(vector<int> &a){
		int num_of_copies=0;
		quickSort(a);
		for (int i=0;i<static_cast<int>(a.size());i++){
			if (a[i]==a[i+1]) {num_of_copies++;}
		}
		return num_of_copies;
	}

int unique(vector<int> &a){
		return static_cast<int>(a.size())-count_copies(a);
	}
int main()
{
		Timer T;
	vector<int> array;
	for (int i=0;i<10000000;i++){
		array.push_back(rand()%500-250); //псевдорандом даже без сида для повторяемости
	}
	//print(array);
	//quickSort(array);
	//print(array);
	T.start();
	//cout<<"Copies: "<<count_copies(array)<<endl;
	cout<<"Unique: "<<unique(array)<<endl;
	T.stop();
	//print(array);
	cout << "Seconds: " << T.elapsedSeconds() << endl;
	return 0;
}
