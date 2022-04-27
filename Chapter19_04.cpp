#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>

using namespace std;

mutex mtx;
int main()

{
    atomic<int> shared_memory(0);

    auto count_func = [&]() {
        for (int i = 0; i < 1000; ++i)
        {
            this_thread::sleep_for(chrono::milliseconds(1));

            //mtx.lock();
            //shared_memory.fetch_add(1);//shared_memory++와 같음

            //std::lock_guard lock(mtx);
            shared_memory++;

            //mtx.unlock();
        }

    };

    thread t1 = thread(count_func);
    thread t2 = thread(count_func);

    t1.join();
    t2.join();

    cout << "After" << endl;
    cout << shared_memory << endl;

    return 0;
}