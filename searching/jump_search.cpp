//also called block search. 
#include <iostream>
using namespace std;


int jump_search(int*arr, int length, int val){
	int low = 0, high = length-1, mid, found = -1;
	int step, i;
	step = length-1;
	for(i=0; i<step; i++)
	{
		if(val < arr[step])
		high = step - 1;
		else
		low = step + 1;
	}
	for(i=low; i<=high; i++)
	{
		if(arr[i] == val)
		return i;
	}
	return found;
}

int main(int argc, char const *argv[])
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int length = sizeof(arr)/sizeof(arr[0]);
	int key = 5;
    
    int  index= jump_search(arr, length, key);
    if(index!= -1){
    	cout<<key<<" is found at index "<< index;
    }else{
    	cout<<key<<" is not in the list"<<endl;
    }
	return 0;
}