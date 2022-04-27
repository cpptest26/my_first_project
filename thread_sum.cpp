#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <mutex>
#include <atomic>
#include <functional>


using namespace std;

int main()
{

{
    int sum = 0;

    mutex mtx;

    auto sum_a_to_b = [&] (const int & a, const int & b)
    {
        auto id = this_thread::get_id();
        cout << id << "start\n";

        for(int i = a; i <=b; i++)
        {
            this_thread::sleep_for(std::chrono::milliseconds(1));
            mtx.lock();
            sum +=i;
            mtx.unlock();

        }

        cout << id << " end\n";
    };

    thread t1(sum_a_to_b, 1, 50);
    thread t2(sum_a_to_b, 51, 100);

    t1.join();
    t2.join();

    cout << " 1~100까지의 합: " << sum << endl;

    }

    return 0;
}
