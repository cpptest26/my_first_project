#include <iostream>



using namespace std;

void printArray(const int array[], const int length) 
// 배열 원소들을 출력할때 배열 길이도 알아야하므로 같이 넘겨준다. 값이 바뀔 일은 없으니 const
{
	for (int index = 0; index < length; ++index)
		cout << array[index] << " ";
	cout << endl;

}

int main()
{
	const int length = 5;

	int array[length] = { 3, 5, 2, 1, 4};

	cout << "Your first value is: " << endl;
	
	printArray(array, length);

	for (int i = 0; i < length - 1; ++i)
	{
		int smallestIndex = i;
		
		for (int j = i + 1; j < length; ++j)
		{
			if (array[smallestIndex] > array[j])
			{
				smallestIndex = j; 
			}
		}

        // 작은 for문이 끝나면, 즉 해당 i와 비교된 j들 중 가장 작은 원소값의 인덱스가 smallestIndex에 저장된다.  

		// 작은 for문이 끝난 후 인덱스가 smallestIndex인 원소와 인덱스가 i인 원소와 자리를 바꿔준다. 
        // 자연스레 가장 작은 값이 앞에 위치하게 된다. 
		int temp = array[smallestIndex];
		array[smallestIndex] = array[i]; 
		array[i] = temp;

		cout << "your array is: " << endl;
		printArray(array, length);
	}

	cout << "Now your array is: " << endl;
	printArray(array, length); // 정렬된  1 2 3 4 5 가 출력 될 것.

	return 0;
}