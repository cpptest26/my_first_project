#include <iostream>

using namespace std;

int main()
{
   const int row = 3;
   const int col = 5;

   const int s2da[row][col] = 
   {
       {1, 2, 3, 4, 5},
       {6, 7, 8, 9, 10},
       {11, 12, 13, 14, 15}
   };

   // 💛 2차원 동적 배열 할당 받음. row개의 포인터 원소들을 가진 1차원 배열.
int ** matrix = new int* [row]; 

// 💛 2차원 배열 matrix의 원소는 각각의 1차원 배열의 시작 주소. 
// 💛col개의 원소를 가진 1차원 배열 row개 만큼 동적 할당.
for (int r = 0; r < row; ++r)
    matrix[r] = new int[col]; 


// 💛 초기화 작업. 이중포인터에 [][]로 원소들에 접근할 수 있다.
for (int r = 0; r < row; ++r)
    for (int c = 0; c < col; ++c)
        matrix[r][c] = r * col + c;     // 행마다   0 1 2 3    4 5 6 7    8 9 10 11  이런식으로 초기화 될것

// print all elements
for (int r = 0; r < row; ++r)
{
    for (int c = 0; c < col; ++c)
        cout << matrix[r][c] << " ";  
    cout << endl;  
}



for (int r = 0; r < row; ++r)
    delete [] matrix[r];

delete [] matrix;




    return 0;
}
