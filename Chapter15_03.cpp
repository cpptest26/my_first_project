#include <iostream>
#include "AutoPtr.h"
#include "Resource.h"
#include "Timer.h"


using namespace std;

// template<class T>
// void MySwap(T &a, T &b)
// {
// T tmp{ std::move(A)};
// a = std::move(b);
// b = std::move(tmp);
// }


AutoPtr<Resource> generateResource()  // AutoPtr<Resource> 타입을 리턴하는 함수
{
   // 10000000 의 length를 가진 Resource타입의 멤버를 가지는 AutoPtr 객체 생성
	AutoPtr<Resource> res(new Resource(10000000));

    // cout << res1.m_ptr << endl;

    // AutoPtr<Resource> res2 = res1;

    // cout << res1.m_ptr << endl;
    // cout << res2.m_ptr << endl;

	return res;
}

int main()
{

    streambuf * orig_buf = cout.rdbuf();
	// AutoPtr<Resource> res(new Resource(10000000));

    // cout << res1.m_ptr << endl;

    //  AutoPtr<Resource> res2 = std::move(res1);

    //  cout << res1.m_ptr << endl;
    // cout << res2.m_ptr << endl;

    Timer timer;
    {
        AutoPtr<Resource> main_res;
        main_res = generateResource();

    }
        cout.rdbuf(orig_buf);
        cout << timer.elapsed() << endl;

        return 0;
}



// {

//     AutoPtr<Resource> res1(new Resource(3));
//     res1->setAll(3);

//     AutoPtr<Resource> res12(new Resource(5));
//     res2->setAll(5);

//     MySwap(res1, res2);

//     res1->print();
//     res2->print();


// }

// {
//     vector<string> v;
//     string str = "Hello";

//     v.push_back(str);

//     cout << str << endl;
//     cout << v[0] << endl;

//     v.push_back(std::move(str));

//     cout << str << endl;
//     cout << v[0] << " " << v[1] << endl;
// }

// void print()
// {
//     for(unsigned i = 0; i < m_length; ++i)
//     cout << m_data[i] << " ";
//     cout << endl;
// }

// void setAll(const int& v)
// {
//     for (unsigned i = 0; i < m_length; ++i)
//     m_data[i] = v;

// {
//     std::string x{ "abc"};
//     std::string y{ "de"};

//     std::cout << "x : " << x << std::endl;
//     std::cout << "y : " << y << std::endl;

//     MySwap(x,y);

//     std::cout << "x : " << x << std::endl;
//     std::cout << "y : " << y << std::endl;





// 	streambuf * orig_buf = cout.rdbuf();
// 	// cout.rdbuf(NULL); 화면에 출력되는 메세지들 끄기. 시간 어마어마하게 걸릴테니까 😎

// 	Timer timer;
// 	{
// 		AutoPtr<Resource> main_res; // ⭐
// 		main_res = generateResource(); // ⭐ generateResource() 리턴값은 R-value 
// 	}
// 		cout.rdbuf(orig_buf);
// 		cout << timer.elapsed() << endl; // 실행시간 재서 출력
// 	}
// }