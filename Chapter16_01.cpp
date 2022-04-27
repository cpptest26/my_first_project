#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <initializer_list>
#include <list>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void sequence_containers()
{//vector
//     {
//         vector<int> vec;
//         for(int i = 0; i < 10; ++i)
//         vec.push_back(i);

//         for(auto & e : vec)
//         cout << e << " ";
//         cout << endl;    
// }
    //deque
// {
//     deque<int> deq;
//     for(int i = 0; i < 10; ++i)
//     {
//         deq.push_back(i);
//         deq.push_front(i);

//     }
//     for(auto & e : deq)
//     cout << e << " ";
//     cout << endl;

// }
    //list
    // {
    //     list<int> l;

        
    //         l.push_back(100);
    //         l.push_back(100);
    //         l.push_back(2);
    //         l.push_back(30);
    //         l.push_back(30);
    //         l.push_back(30);

    //     list<int>::iterator iter;
    //     for(iter = l.begin(); iter != l.end(); iter++
    //     )
    //     {
    //         cout << *iter << " ";
    //     }
    //     cout << endl;

    //     l.unique();
    //     for( iter = l.begin(); iter != l.end(); iter++)
    //     {
    //         cout << *iter << " " ;
        
    //     }
    //     cout << endl;    
    // }
}

void associative_containers()
{
    //set
    // {
    //     set<string> str_set;

    //     str_set.insert("Hello");
    //     str_set.insert("World");
    //     str_set.insert("Hello");

    //     cout << str_set.size()
    //     << endl;

    //     for(auto & e : str_set)
    //     cout << e << " ";
    //     cout << endl;

    // }

    //multiset
    // {
    //     std::multiset<string> str_set;

    //     str_set.insert("Hello");
    //     str_set.insert("Helld");
    //     str_set.insert("World");
    //     str_set.insert("Helld");

    //     cout << str_set.size() << endl;

    //     for(auto & e : str_set)
    //         cout << e << " ";
    //         cout << endl;
    // }

    //map
    // {
    //     std::map<char, int> map;

       
    //     map['a'] = 10;
    //     map['b'] = 20;
    //     map['c'] = 50;

    //     cout << map['a'] << endl;

    //     map['a'] = 100;

    //     cout << map['a'] << endl;

    //     for(auto & e : map)
    //         cout << e.first << " " << e.second << " ";
    //         cout << endl;

    // }


    //multimap
    // {
    //     std::multimap<char,int> map;
    //     map.insert(std::pair('a', 10));
    //     map.insert(std::pair('b', 10));
    //     map.insert(std::pair('c', 10));
    //     map.insert(std::pair('a', 100));

    //     cout << map.count('a') << endl;

    //     for(auto & e : map)
    //     cout << e.first << " " << e.second << " ";
    //     cout << endl;



    // }
    }

    void container_adapters()
    {
        // //stack
        // {
        //     cout << "Stack" << endl;

        //     std::stack<int> stack;
        //     stack.push(1);
        //     stack.empty();
        //     stack.empty();
        //     cout << stack.top() << endl;
        //     cout << stack.top() << endl;

        // }

        //stack
        // {
        //     std::stack<int> s;
        //     cout << "s에 원소가 들어가는 순서" << endl;
        //     for(int i = 1; i <=5; i++)
        //     {
        //         s.push(i);
        //         cout << i << " ";
        //     }
        //     cout << endl;

        //     cout << " s에서 원소가 나오는 순서" << endl;
        //     while(!s.empty())
        //     {
        //         cout << s.top() << " ";
        //         s.pop();
        //     }
        //     cout << endl;
            
        // }

        //queue
        // {
        //     cout << "Queue" << endl;

        //     std::queue<int> queue;
        //     queue.push(1);
        //     queue.push(2);
        //     queue.push(3);
        //     cout << queue.front() << " " << queue.back() << endl;
        //     queue.pop();
        //     cout << queue.front() << " " << queue.back() << endl;

        // }

        //priority queue
        // {
        //     cout << "Priority queue" << endl;

        //     std::priority_queue<int> queue;

        //     for (const int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
        //     queue.push(n);

        //     for (int i = 0; i < 10; ++i)
        //     {
        //         cout << queue.top() << endl;
        //         queue.pop();

        //     }
        // }
        //priority queue
        {
            priority_queue<int> pq;
            pq.push(5);
            pq.push(30);
            pq.push(100);
            pq.push(2);
            pq.push(7);

            while (!pq.empty()){
                cout << pq.top() << " ";
                pq.pop();
            }
            cout << endl;


        }
      



        }





int main()
{

    //sequence_containers();
    //associative_containers();
    container_adapters();


    return 0;}