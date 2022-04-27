#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Examples
{
    public:

    void ex1()
    {
        std::vector<int> vect;
        for (std::vector<int>::iterator itr = vect.begin(); itr != vect.end(); ++itr)
            cout << *itr;

        for (auto itr = vect.begin(); itr != vect.end(); itr++)
            cout << *itr;

        for (auto itr : vect)
            cout << itr;  //이렇게 줄일 수 있음 for(const & itr : vect)
    }

    void ex2()
    {
        int x = int();

        auto auto_x = x;

        const int &crx = x;

        auto auto_crx1 = crx; //auto 형 받을 때 const 떼 버림

        const auto& auto_crx2 = crx; //auto에 const 와 & 받아줘야함

        volatile int vx = 1024; //volatile은 값이 자주 변하기 때문에 최적화 할 때 빼 달라는 말

        auto avx = vx; //여기도 volatile 떼고 int 만 남김

        volatile auto vavx = vx;
    }

    // template<class T>
    // void func_ex3(T arg)
    // {}

    template<class T>
    void func_ex3(const T& arg)
    {}

    void ex3()
    {
        const int &crx = 123;

        func_ex3(crx);//const 와 &떼버림
    }

    void ex4()
    {
        const int c = 0;
        auto & rc = c;
        //rc= 123; //error
    }

    void ex5() //amendment
    {
        int i = 42;
        auto&& ri_1 = i; //l-value(r로 하고싶다 하지만 안됨)
        auto&& ri_2 = 42; // r-value
    }

    void ex6()
    {
        int x = 42;
        const int *p1 = &x;
        auto p2 = p1;
        // *p2 = 43; //error
        // const int * 까지 찾아줌

    }

    template<typename T, typename S>
    void func_ex7(T lhs, S rhs)
    {
        auto prid1 = lhs * rhs;

        typedef decltype(lhs * rhs) product_type;

        product_type prod2 = lhs * rhs;

        decltype(lhs * rhs) prod3 = lhs * rhs;
    }

    template<typename T, typename S>
    auto func_ex8(T lhs, S rhs )-> decltype(lhs * rhs)
    {
        return lhs * rhs;
    }

    void ex7_8()
    {
        func_ex7(1.0, 345);
        func_ex8(1.2, 345);
    }

    struct S
    {
        int m_x;

        S()
        {
            m_x = 42;
        }
    };

    void ex9()
    {
        int x;
        const int cx = 42;
        const int& crx = x;
        const S *p = new S();

        auto a = x;             
        auto b = cx;
        auto c = crx;
        auto d = p;
        auto e = p->m_x;
        //e는 integer가 된다. p는 const 이지만 복사해서 상관없어 지는 것


        //declared type
        //선언이 된 타입 그대로 가져옴
        //&, *도 그대로 가져온다
        typedef decltype(x)         x_type;
        typedef decltype(cx)        cx_type;
        typedef decltype(crx)       crx_type;
        typedef decltype(p->m_x)    m_x_type;

        //with const
        typedef decltype((x))       x_with_parens_type;
        typedef decltype((cx))      cx_with_parens_type;
        typedef decltype((crx))     crx_with_parens_type;
        typedef decltype((p->m_x))  m_x_with_parens_type;//add references to lvalues
    }

    const S foo()
    {
        return S();
    }

    const int& foobar()
    {
        return 123;
    }

    void ex10()
    {
        std::vector<int> vect = {42, 43};

        auto a = foo();
        typedef decltype (foo()) foo_type;

        auto b = foobar();
        typedef decltype(foobar()) foobar_type;

        auto itr = vect.begin();
        typedef decltype(vect.begin()) iterator_type;

        auto first_element = vect[0];
        decltype(vect[1]) second_element = vect[1];
    }

    void ex11()
    {

        int x = 0;
        int y = 0;
        const int cx = 42;
        const int cy = 43;
        double d1 = 3.14;
        double d2 = 2.72;

        //1.typedef decltype로 결정되는 데이터 타입과
        //2.auto 로 결정되는 데이터 타입간의 차이 확인

        typedef decltype(x * y)         prod_xy_type;
        auto a = x * y;

        typedef decltype(cx * cy)           prod_cxcy_type;
        auto b = cx * cy;


        //& is added. 변수의 데이터 타입이 같은 경우

        typedef decltype(d1 < d2 ? d1 : d2)         cond_type;
        auto c = d1 < d2 ? d1 : d2;

        typedef decltype(x < d2 ? x : d2)           cond_type_mixed;
        auto d = x < d2 ? x : d2;
    }
    //floating point min = fpmin
    template<typename T, typename S>
    auto fpmin_wrong(T x, S y)-> decltype(x < y ? x : y)
    {
        return x < y ? x : y;
    }

    template<typename T, typename S>

    auto fpmin(T x, S y)->
    typename std::remove_reference<decltype(x < y ? x : y)>::type
    {
        return x < y ? x : y;
    }//refernce가 자동으로 붙는 게 싫으면 remove

    void ex12()
    {
        int i = 42;
        double d = 45.1;

        auto a = std::min (static_cast<double>(i), d);

        int &j = i;

        typedef decltype(fpmin_wrong(d, d)) fpmin_return_type1; //double의 referencd
        typedef decltype(fpmin_wrong(i, d)) fpmin_return_type2; //그냥 double
        typedef decltype(fpmin_wrong(j, d)) fpmin_return_type3; //그냥 double
        typedef decltype(fpmin(d,d)) fpmin_return_type4;//d와 d 즉 타입이 double 로 같지만 &추가로 붙이지 않음
    }

    void ex13()//vect is empty
    {
        std::vector<int> vect;
        typedef decltype(vect[0]) integer;
    }
    
    template<typename R>
    class SomeFunctor
    {
        public:
        typedef R result_type;

        SomeFunctor()
        {}

        result_type operator() ()
        {
            return R();
        }
    };

    void ex14()
    {
        SomeFunctor<int> func;
        typedef decltype(func)::result_type integer;//nested type
    }

    void ex15()
    {
        auto lambda = []() {return 42;};
        decltype(lambda) lambda2(lambda);//copy 해서 가지고옴//call by value
        decltype((lambda)) lambda3(lambda);//&func3 = func ; ref해서 가져온다//call by reference

        cout << "Lambda functions" << endl;
        cout << &lambda << " " << &lambda2 << endl;//주소값 복사만 해서 다른거
        cout << &lambda << " " << &lambda3 << endl;//참조해서 가져온거라 같음 
    }

    void ex16()
    {//generic lambda;
        auto lambda = [](auto x, auto y)
        {
            return x + y;
        };

        cout << lambda(1.1, 2) << " " << lambda(3, 4) << " " << lambda(4.5, 2.2) << endl;

    }

};


int main()
{
    Examples examples;

    examples.ex1();
    examples.ex2();
    examples.ex3();
    examples.ex10();
    examples.ex12();
    examples.ex14();
    examples.ex15();
    examples.ex16();

}