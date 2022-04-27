#include <vector>
#include <iostream>
#include <list>
#include <set>
#include <map>

using namespace std;

// int main()
// {
//     vector<int> container;
//     for (int i = 0; i < 10; ++i)
//     container.push_back(i);
//     // container.(make_pair(i, char(i+65)));

//     vector<int>::iterator itr;
//     itr = container.begin();
//     while(itr != container.end())
//     {
//         cout << *itr << " "; //연산자 오버로딩

//         ++itr;
//     } // vector에서 반복자 사용예시
//     cout << endl;

//     for (auto citr = container.begin(); citr != container.end(); ++citr)
//     {
//         cout << *citr << " ";
//         //cout << citr ->first << " " << citr->second << endl;//map사용시 출력
//     }
//     cout << endl;

//     for (auto & citr : container)
//         cout << citr << " ";
//         cout << endl;

//     return 0;
// }

//list 사용 예시
// int main()
// {
//     list<int> container;

//     for(int i = 0; i < 10; ++i)
//     container.push_back(i);

//     vector<int>::const_iterator itr;

//     for(auto &itr : container)
//     cout << itr << " ";
//     cout << endl;
// }

//set의 사용예시

// int main()
// {
//     set<int> container;

//     for(int i = 0; i < 10; ++i)
//     container.insert(i);

//     vector<int>::const_iterator itr;

//     for(auto &itr : container)
//     cout << itr << " ";
//     cout << endl;
    
// }

//map에서 사용예시

int main()
{
    map<int,char> container;

    for (int i = 0; i < 10; ++i)
    container.insert(make_pair(i, char(i+65)));

    vector<int>::iterator itr;

    for (auto & itr : container)
    cout << itr->first << " " << itr->second << endl;
    cout << endl;

}
