#include<iostream>
using namespace std;
// linear searching: every key/element is searched from first element to last element

int linear_search(int* arr, int length, int key){
  int index = -1;
  for (int i = 0; i < length; i++)
  {
  	if (arr[i]==key)
  	{
  		index = i;
  		break;
  	}
  }
  return index;
}

int main(int argc, char const *argv[])
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int length = sizeof(arr)/sizeof(arr[0]);
	int key = 0;
	int index = linear_search(arr, length, key);
    
    if(index!= -1){
    	cout<<key<<" is found at index "<< index;
    }else{
    	cout<<key<<" is not in the list"<<endl;
    }
	return 0;
}