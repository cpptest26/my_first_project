#include <iostream>
using namespace std;

void last()
{
	cout << "Last" << endl;  // 💛 5 💛
	cout << "Throws exception" << endl;  // 💛 6 💛

	throw 'a';
	cout << "End Last" << endl; // 🟦 실행 X 🟦
}

void third()
{
	cout << "Third" << endl; // 💛 4 💛

	last();

	cout << "End third" << endl;  // 🟦 실행 X 🟦
}

void second()
{
	cout << "Second" << endl; // 💛 3 💛

	try
	{
		third();
	}
	catch (double)
	{
		std::cerr << "Second caught double exception!" << endl;  // 🟦 실행 X 🟦
	}
	cout << "End second" << endl;  // 🟦 실행 X 🟦
}

void first()
{
	cout << "First" << endl;  // 💛 2 💛

	try
	{
		second();
	}
	catch (double)
	{
		std::cerr << "first caught int exception!" << endl; // 💛 7 💛
	}
	cout << "End first" << endl; // 💛 8 💛
}

int main()
{
	cout << "Start" << endl;  // 💛 1 💛

	try
	{
		first(); 
	}
	catch (double)
	{
		std::cerr << "main caught int exception!" << endl;  // 🟦 실행 X 🟦
	}
	//uncaught exception

    catch (...) //catch-all-handlers
	{
		std::cerr << "main caught ellipses exception!" << endl;  // 🟦 실행 X 🟦
	}
	cout << "End of main" << endl; // 💛 9 💛
}