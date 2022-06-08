#include <iostream>
using namespace std;

int binary_search(int* arr, int length, int key){
    int i, n, beg, end, mid, found = -1;
	beg= 0, end= length-1;

	while ( beg <= end){
		mid = (beg + end) / 2;
		if(arr[mid] == key){
			found=mid;
			break;
		}else if(arr[mid] > key)
			end = mid - 1;
		else
			beg = mid + 1;
	}
	
	return found;
}

int main(int argc, char const *argv[])
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int length = sizeof(arr)/sizeof(arr[0]);
	int key = 10;
    
    int  index= binary_search(arr, length, key);
    if(index!= -1){
    	cout<<key<<" is found at index "<< index;
    }else{
    	cout<<key<<" is not in the list"<<endl;
    }
	return 0;
}