#include <iostream>
#include <cassert>

using namespace std;

class ArrayInt
{
private:
	int m_length;
	int *m_data;
	
	void zeroing(int start, int end){
			for(int i=start; i<end;i++){
				m_data[i]=0;
			}
		}
	void zeroing(){
			zeroing(0,m_length);
		}
public:
	ArrayInt(): m_length(0), m_data(nullptr)
	{ }

	ArrayInt(int length) : m_length(length)
		{
			assert(length >= 0);

			if (length > 0){
				m_data = new int[length];
				zeroing();
			}
			else
				m_data = nullptr;
		}

	void erase()
		{
			delete[] m_data;
			m_data = nullptr;
			m_length = 0;
		}
	int getLength() { return m_length; }

	int& operator[](int index)
		{
			assert(index >= 0 && index < m_length);
			return m_data[index];
		}

	void resize(int newLength)
		{
			if (newLength == m_length)
				return;
			if (newLength <= 0)
				{
					erase();
					return;
				}
			int *data = new int[newLength];
			if (m_length > 0)
				{
					int elementsToCopy = (newLength > m_length) ? m_length : newLength;
					for (int index=0; index < elementsToCopy ; ++index)
					data[index] = m_data[index];
				}

			delete[] m_data;
			m_data = data;
			zeroing(m_length,newLength);
			m_length = newLength;

		}

	void pop_back(){
			resize(m_length-1);
		};

	void pop_front(){
			int newLength = m_length-1;
			if (newLength <= 0){
				erase();
				return;
			}
			int *data = new int[newLength];

					for (int index=1; index < m_length ; index++)
					data[index-1] = m_data[index];

			delete[] m_data;
			m_data = data;
			m_length = newLength;
		};

	void insertBefore(int value, int index)
		{
			assert(index >= 0 && index <= m_length);
			int *data = new int[m_length+1];
			for (int before=0; before < index; ++before)
				data[before] = m_data[before];
			data [index] = value;
			for (int after=index; after < m_length; ++after)
				data[after+1] = m_data[after];
			delete[] m_data;
			m_data = data;
			++m_length;
		}

	void push_back(int value) { insertBefore(value, m_length); }
	void push_front(int value) { insertBefore(value, 0); }

	void print() const {
			for(int i=0;i<m_length;i++){
				cout<<m_data[i]<<" ";
			}
			cout<<endl;
		}


	//sort
	void quickSort(int start, int end)
	{
			if (end>m_length-1 || start<0) return;
		int i = start;
		int j = end;
		int pivot = m_data[(start+end)/2];
		int buffer;

		while (i <= j)
		{
			while (m_data[i] < pivot) i++;
			while (m_data[j] > pivot) j--;
			if (i <= j)
			{
				buffer = m_data[i];
				m_data[i] = m_data[j];
				m_data[j] = buffer;
				i++;
				j--;
			}
		}
		if (j > start) quickSort(start, j);
		if (i < end) quickSort(i, end);
	}

	//сортировка всего массива целиком
	void quickSort(){
			quickSort(0,m_length-1);
		}

	//сортировка первых n элементов
	void quickSort(int len){
			len-=1;
			if (len>m_length){len=m_length-1;}
			quickSort(0,len);
		}



	~ArrayInt()
		{
			delete[] m_data;
		}
};


int main()
	{
		ArrayInt arr;
for (int i=0;i<25;i++){
	arr.push_back(rand()%50-25); //псевдорандом даже без сида для повторяемости
}
		arr.print();
		arr.quickSort();
		arr.print();
		arr.pop_back();
		arr.pop_front();
		arr.print();
		return 0;
	}
