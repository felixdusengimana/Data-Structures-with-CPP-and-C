#include <iostream>
using namespace std;

void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubble_sort(int* arr, int len){
int i, j;
for (i = 0; i < len-1; i++)
// Last i elements are already in place
	for (j = 0; j < len-i-1; j++)
		if (arr[j] > arr[j+1])
		swap(&arr[j], &arr[j+1]);

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

	bubble_sort(arr, len);
	printArray(arr, len);
	return 0;
}