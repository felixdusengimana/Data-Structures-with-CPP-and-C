#include <iostream>
using namespace std;

void insertion_sort(int* arr, int len){
  int key, j;

  for (int i = 0; i < len; i++)
  {
  	key = arr[i];
  	j = i-1;

  	while(j>=0&&arr[j] > key){
  		arr[j+1] = arr[j];
  		j = j-1;
  	}

  	arr[j+1] = key;
  }
}

void printArray(int* arr,int len){
	for (int i = 0; i < len; i++)
	{
		cout<<arr[i]<<endl;
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {10, 2, 4, 6,7 ,8,9 ,7};
	int len = sizeof(arr)/sizeof(arr[0]);

	insertion_sort(arr, len);
	printArray(arr, len);
	return 0;
}