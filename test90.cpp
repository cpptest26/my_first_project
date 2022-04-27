#include <iostream>
#include <cassert>

using namespace std;

class IntList
{
private:
	int m_list[10] = { 1, 2 ,3, 4, 5, 6, 7, 8, 9 , 10 };

public:
	int & operator [] (const int index) 
	{
		assert(index >= 0);
		assert(index < 10);

		return m_list[index];
	}

	const int & operator [] (const int index) const 
	{
		assert(index >= 0);
		assert(index < 10);

		return m_list[index];
	}
};

int main()
{
	const IntList my_list;

	cout << my_list[3] << endl;

	return 0;
}