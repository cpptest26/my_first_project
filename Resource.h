#include <iostream>
using namespace std;

class Resource
{
public:
	int * m_data = nullptr;
	unsigned m_length = 0;

public:
	Resource() // 기본 생성자
	{
		cout << "Resource constructed" << endl;
	}

	Resource(unsigned length) // 일반 매개변수 1개 생성자
	{
		cout << "Resource length constructed" << endl;
		this->m_data = new int[length];
		this->m_length = length;
	}

	Resource(const Resource &res) // 💎복사 생성자💎 
	{
		cout << "Resource copy constructed" << endl;
		
		Resource(res.m_length);

		for (unsigned i = 0; i < m_length; ++i)  // 내용물을 전부 깊은 복사 (시간이 꽤 걸림)
			m_data[i] = res.m_data[i];
	}
 
	~Resource()  // 소멸자
	{
		cout << "Resource destroyed" << endl;
	}

	Resource & operator = (Resource & res)  // 💎대입 연산자 오버로딩💎
	{
		cout << "Resource copy assignment" << endl;

		if (&res == this) return *this; // 대입하려는게 자기 자신이면 아무것도 안함
		
		if (this->m_data != nullptr) delete[] m_data; // 1. 내 자신의 m_data 비워주기

		m_length = res.m_length; // 2. 대입으로 넘겨받은 res의 length 로 내 length 갱신
		
		m_data = new int[m_length]; // 3. 비워진 내 자신의 m_data에 새로운 공간 할당받기
		for (unsigned i = 0; i < m_length; ++i) // 4. m_data내용물 넣기.
			m_data[i] = res.m_data[i]; //  대입으로 넘겨받은 res의 m_data 내용물들을 **내 m_data**에 깊은 복사

		return *this;

	}   
};