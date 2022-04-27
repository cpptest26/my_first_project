#include <iostream>
#include <memory>

using namespace std;

class Resource
{
    public:
    int *m_data = nullptr;
    unsigned m_length = 0;

    public:
    Resource()
    {
        cout << "Resource constructed" << endl;
    }

    Resource(unsigned length) 
	{
		cout << "Resource length constructed" << endl;
		this->m_data = new int[length];
		this->m_length = length;
	}
	
	Resource(const Resource &res) // 복사 생성자 
	{
		cout << "Resource copy constructed" << endl;

		Resource(res.m_length);

		for (unsigned i = 0; i < m_length; ++i)  // 깊은 복사
			m_data[i] = res.m_data[i];
	}
	
	~Resource()  // 소멸자
	{
		cout << "Resource destroyed" << endl;
	}
	
	Resource & operator = (Resource & res)  // 대입 연산자 오버로딩
	{
		cout << "Resource copy assignment" << endl;

		if (&res == this) return *this; 

		if (this->m_data != nullptr) delete[] m_data; 

		m_length = res.m_length; 

		m_data = new int[m_length]; 
		for (unsigned i = 0; i < m_length; ++i) 
			m_data[i] = res.m_data[i]; //  깊은 복사

		return *this;
	}

    void print()  // Resource의 동적 배열 m_data의 모든 원소값을 출력한다.
	{
		for (unsigned i = 0; i < m_length; ++i)
				std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}

	void setAll(const int& v) // Resource의 동적 배열 m_data 의 모든 원소값을 v 값으로 설정한다.
	{
		for (unsigned i = 0; i < m_length; ++i)
				m_data[i] = v;
	}
};

void doSomething2(Resource *res)
{

    res->setAll(10);
    res->print();
}

int main()
{
    
        //Resource *res = new Resource(10000000);
        //std::unique_ptr<Resource> res (new Resource(10000000));

    //     std::unique_ptr<int> upi(new int);

    //    std::unique_ptr<Resource> res1 = std::make_unique<Resource>(5);


    //     std::unique_ptr<Resource> res1(ptr);

    //     res1->setAll(5);
    //     res1->print();

    //     std::unique_ptr<Resource> res2;

    //     std::cout << std::boolalpha;
    //     std::cout << static_cast<bool>(res1) << std::endl;
    //     std::cout << static_cast<bool>(res2) << std::endl;

    //     //res2 = res1;
    //     res2 = std::move(res1);
       
    //     std::cout << std::boolalpha;
    //     std::cout << static_cast<bool>(res1) << std::endl;
    //     std::cout << static_cast<bool>(res2) << std::endl;

    //     if(res1 != nullptr) res1->print();
    //     if(res2 != nullptr) res2->print();
        
{
    auto res1 = std::make_unique<Resource>(5);
    res1->setAll(1);
    res1->print();

    std::cout << std::boolalpha;
    std::cout << static_cast<bool>(res1) << std::endl; //true출력



    res1 = doSomething2(std::move(res1));

    std::cout << std::boolalpha;
    std::cout << static_cast<bool>(res1) << std::endl;
    res1->print();


}
    
}
