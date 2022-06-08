// Also called extrapolation it is a combination of binary and linear searches
#include <iostream>
// #define MAX=10
using namespace std;

int interpolation_search(int*arr, int length, int val){
	int low = 0, high = length-1, mid, found = -1;

    while(low<=high){
    	mid=low + (high-low) * ((val - arr[low]) / (arr[high] - arr[low]));
    	// cout<<low<<"+"<<"("<<high-low<<")*(("<<val<<"-"<<arr[low]<<") /("<<arr[high]<<"-"<<arr[low]<<"))="<<mid<<endl;
    	if(val == arr[mid]) return mid;
    	if(val < arr[mid]) high = mid - 1;
    	else low = mid + 1;
    }
	return found;
}
int main(int argc, char const *argv[])
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int length = sizeof(arr)/sizeof(arr[0]);
	int key = 5;
    
    int  index= interpolation_search(arr, length, key);
    if(index!= -1){
    	cout<<key<<" is found at index "<< index;
    }else{
    	cout<<key<<" is not in the list"<<endl;
    }
	return 0;
}