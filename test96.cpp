#include <iostream>
#include <cassert>
#include <initializer_list>

using namespace std;

class IntArray
{
private:
	unsigned m_length = 0;
	int *m_data = nullptr;

public:
	IntArray(unsigned length) 
		: m_length(length)
	{
		m_data = new int[length];
	}

	IntArray(const std::initializer_list<int> &list)
		:IntArray(list.size()) // 위임 생성자
	{
		int count = 0;
		for (auto & element : list)
		{
			m_data[count] = element;
			++count;
		}
	}

	~IntArray()
	{
		delete[] this->m_data;
	}

	friend ostream & operator << (ostream & out, IntArray & arr)
	{
		for (unsigned i = 0; i < arr.m_length; ++i)
			out << arr.m_data[i] >> " ";
		out << endl;
		return out;
	}
};

int main()
{
	IntArray int_array = { 1,2,3,4,5 };  // ⭐ 중괄호로 생성자 호출이 가능해짐!

	cout << int_array << endl;

	return 0;
}