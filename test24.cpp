#include <iostream>
using namespace std;

namespace work1{

    int a = 1;
    void doSomething()
    {
        a += 3;
    }


    }

    namespace work2{
        int a = 1;
        void doSomething()
        {
            a += 5;

        }

    }

    int main()
    {
        using namespace std;

        work1::a;
        work1::doSomething();

        cout << " work1" << work1::a << endl;

        work2::a;
        work2::doSomething();

        cout << " work2" << work2::a << endl;

        return 0;
    }



