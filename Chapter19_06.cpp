#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <vector>
#include <atomic>
#include <future>
#include <numeric>
#include <execution>
#include <algorithm>

using namespace std;

mutex mtx;

void dotProductNaive(const vector<int> &v0, const vector<int> &v1, const unsigned i_start, const unsigned i_end, unsigned long long &sum)
{
    for(unsigned i = i_start; i < i_end ; i++)
    {
        sum+= (v0[i] * v1[i]);
      
    }
    //cout << "Thread end" << endl;
}

void dotProductAtomic(const vector<int> &v0, const vector<int> &v1, const unsigned i_start, const unsigned i_end, unsigned long long &sum)
{
    for (unsigned i = i_start; i < i_end; i++)
    {

        sum += v0[i] * v1[i];
    }
}

void dotProductLock(const vector<int> &v0, const vector<int> &v1, const unsigned i_start, const unsigned i_end, unsigned long long &sum)
{
    for (unsigned i = i_start; i < i_end; i++)
    {
        mtx.lock();
        sum += (v0[i] * v1[i]);
        mtx.unlock();
        
    }
}

auto dotProductFuture(const vector<int> &v0, const vector<int> &v1, const unsigned i_start, const unsigned i_end)
{
    int sum = 0;
    for (unsigned i = i_start; i < i_end; i++)
    {

        sum += (v0[i] * v1[i]);
    }
    return sum;
}

    int main()
{
    /*  v0= {1, 2, 3}
        v1= {4, 5, 6}
        v0_dot_v1 = 1*4 + 2*5 + 3*6;
        */
        
    const long long n_data = 100'100'000;
    const unsigned n_threads = 8;

    //initializer vectors
    std::vector<int> v0, v1;
    v0.reserve(n_data);
    v1.reserve(n_data);

    random_device seed;
    mt19937 engine(seed());
    uniform_int_distribution<> uniformDist(1, 10);

    for(long long i = 0; i < n_data; ++i)
    {
        v0.push_back(uniformDist(engine));
        v1.push_back(uniformDist(engine));
    }
 
    // cout << "std::inner_product" << endl;
    // {
    //     const auto sta = chrono::steady_clock::now();

    //     const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);//vec1 은 begin만 있어도 됨. ull은 unsigned longlong의 약자

    //     const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

    //     cout << dur.count() << endl;
    //     cout << sum << endl;
    //     cout << endl;

    // }

    // cout << "Naive" << endl;
    // {
    //     const auto sta = chrono::steady_clock::now();

    //     unsigned long long sum = 0;

    //     vector<thread> threads;
    //     threads.resize(n_threads);

    //     const unsigned n_per_thread = n_data / n_threads ;
    //     for(unsigned t = 0; t < n_threads; ++t)
    //     threads[t] = std::thread(dotProductNaive, std::ref(v0), std::ref(v1), t * n_per_thread, (t +1) *n_per_thread );

    //     for (unsigned t = 0; t < n_threads; ++t)
    //         threads[t].join();

    //         const chrono::duration<double> dur= chrono::steady_clock::now() - sta;

    //         cout << dur.count() << endl;
    //         cout << sum << endl;
    //         cout << endl;
    // }

    // cout << "Lock_guard" << endl;
    // {
    //     const auto sta = chrono::steady_clock::now();

    //     unsigned long long sum = 0;

    //     vector<thread> threads;
    //     threads.resize(n_threads);

    //     const unsigned n_per_thread = n_data / n_threads;
    //     for (unsigned t = 0; t < n_threads; ++t)
    //         threads[t] = std::thread(dotProductLock, std::ref(v0), std::ref(v1), t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));

    //     for (unsigned t = 0; t < n_threads; ++t)
    //         threads[t].join();

    //     const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

    //     cout << dur.count() << endl;
    //     cout << sum << endl;
    //     cout << endl;
    // }

    // cout << "Atomic" << endl;
    // {
    //     const auto sta = chrono::steady_clock::now();

    //     unsigned long long sum = 0;

    //     vector<thread> threads;
    //     threads.resize(n_threads);

    //     const unsigned n_per_thread = n_data / n_threads;
    //     for (unsigned t = 0; t < n_threads; ++t)
    //         threads[t] = std::thread(dotProductAtomic, std::ref(v0), std::ref(v1), t * n_per_thread, (t + 1) * n_per_thread, std::ref(sum));

    //     for (unsigned t = 0; t < n_threads; ++t)
    //         threads[t].join();

    //     const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

    //     cout << dur.count() << endl;
    //     cout << sum << endl;
    //     cout << endl;
    // }

    // cout << "futures" << endl;
    // {
    //     const auto sta = chrono::steady_clock::now();

    //     unsigned long long sum = 0;

    //     vector<std::future<int>> futures;
    //     futures.resize(n_threads);

    //     const unsigned n_per_thread = n_data / n_threads;
    //     for (unsigned t = 0; t < n_threads; ++t)
    //         futures[t] = std::async(dotProductFuture, std::ref(v0), std::ref(v1), t * n_per_thread, (t + 1) * n_per_thread);

    //     for (unsigned t = 0; t < n_threads; ++t)
    //        sum += futures[t].get();

    //     const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

    //     cout << dur.count() << endl;
    //     cout << sum << endl;
    //     cout << endl;
    // }

    cout << "실험 6번 - promise\n";
    {
        const auto sta = std::chrono::steady_clock::now();

        vector<std::promise<int>> prom;
        vector<std::future<int>> future;
        vector<std::thread> threads;
        prom.resize(n_threads);
        future.resize(n_threads);
        threads.resize(n_threads);

        unsigned long long sum(0);
        unsigned numPerThread = n_data / n_threads;
        for (unsigned i = 0; i < n_threads; ++i)
        {
            future[i] = prom[i].get_future();
            unsigned long long tempSum(0);
            threads[i] = std::thread([&](std::promise<int> &&prom)
         {
					mtx.lock();
					
					for (unsigned int j = 0; j < numPerThread; ++j)
						tempSum += (v0[j] * v1[j]);
					prom.set_value(tempSum); },
                     std::move(prom[i]));
            threads[i].join();
        }
        for (unsigned int t = 0; t < n_threads; ++t)
            sum += future[t].get();

        const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

        cout << "연산에 소요된 시간 = " << dur.count() << '\n';
        cout << "결과값 = " << sum << '\n';
        cout << '\n';
    }

    // cout << "실험 7번 - std::transform_reduce\n";
    // {
    //     const auto sta = std::chrono::steady_clock::now();
    //     //const auto sum = std::transform_reduce(std::execution::par, v0.begin(), v0.end(), v1.begin(), 0ull);
    //     const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

    //     cout << "연산에 소요된 시간 = " << dur.count() << '\n';
    //     cout << "결과값 = " << sum << '\n';
    //     cout << '\n';
    // }

    return 0;
}





