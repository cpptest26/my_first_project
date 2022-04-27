#include <iostream>

using namespace std;

int getInt()
{
	cout << "Enter an integer number : ";
	int x= 5;
	if (std::cin.fail()) // 입력실패시
	{
		std::cin.clear(); // 플래그값 초기화 
		std::cin.ignore(32767, '\n'); // 버퍼 비워주기 (버퍼 무시)
		cout << "Invaild number, please try again" << endl;
	}
	else
	{
		std::cin.ignore(32767, '\n');
		return x;
	}
}



char getOperator()
{
    while(true)
    {

    
    cout << "Enter an operator(+,-) : ";
    char op;
    cin >> op;

    if( std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');

    }

    std::cin.ignore(32767, '\n');

    if(op == '+' || op == '-')
    return op;
    else
    cout << "Invalid operator, try Again" << endl;
}
}

void printResult(int x, char op, int y)
{
	if (op == '+') cout << x + y << endl;
	else if (op == '-') cout << x - y << endl;
	else
	{
		cout << "Invalid operator" << endl;
	}
}

int main()
{
    int x = getInt();
    char op = getOperator();
    int y = getInt();

    printResult(x, op, y);

    return 0;
}
