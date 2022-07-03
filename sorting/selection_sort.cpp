#include <iostream>
using namespace std;

void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selection_sort(int* arr, int len){
  int i, j, mid_idx;
  for (int i = 0; i < len-1; i++)
  {
  	mid_idx = i;
  	for (int j = i+1; j < len; j++)
  	{
  		if (arr[j]<arr[mid_idx])
  		{
  			mid_idx = j;
  		}
  	}
  	swap(&arr[mid_idx], &arr[i]);
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

	selection_sort(arr, len);
	printArray(arr, len);
	return 0;
}