#include <iostream>
#include <chrono>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <vector>
#include <atomic>
#include <future>
#include <numeric>
#include <execution>

using namespace std;

mutex mtx;

const long long n_data = 100'000'000;
const unsigned n_threads = 16;


