#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono> // ⭐시간 측정에 필요
#include <cmath>
#include <ctime>
#include <functional>

using namespace std;

class Timer
{
    using clock_t = std::chrono::high_resolution_clock;
    using secont_t = std::chrono::duration<double, std::ratio<1>>;

    // Time 타입의 객체가 생성되자마자 start_time 멤버 변수에 시작 시간이 대입된다.
    std::chrono::time_point<clock_t> start_time = clock_t::now();   

public:
    void elapsed()
    {
        std::chrono::time_point<clock_t> end_time = clock_t::now();  // elapsed() 멤버 함수를 실행한 시간

        // elapsed() 멤버 함수가 실행되자마자 end_time - start_time 빼주어 실행 시간을 구하고 출력한다.
        cout << std::chrono::duration_cast<secont_t>(end_time - start_time).count() << endl;
    }
};

int main()
{
    random_device rnd_device;
    mt19937 mersenne_engine{ rnd_device() };

    vector<int> vec(10);
    for (unsigned int i = 0; i < vec.size(); i++)
        vec[i] = i;
    
    std::shuffle(begin(vec), end(vec), mersenne_engine); // 랜덤하게 섞기

    /*for (auto &e : vec) cout << e << " " ; // 정렬 전 벡터 상태 출력
    cout << endl;*/

    Timer timer; // Timer 타입의 객체를 생성(시작 시간 저장)

    std::sort(begin(vec), end(vec)); // 정렬

    timer.elapsed();  // 실행 시간 측정 및 출력

    /*for (auto &e : vec) cout << e << " " ; // 정렬 후 벡터 상태 출력
    cout << endl;*/

    return 0;
}