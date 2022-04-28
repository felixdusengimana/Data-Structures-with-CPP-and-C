#include <iostream>

using namespace std;

/* Implementatin of dynamic array in c++*/

class DynamicArray
{
public:

	int capacity = 1;
	int  *arr = create_array(capacity);
	int n = 0;

	int size(){
		return n;
	}

	int getitem(int index){
        if(index<0 || index>n){
        	cout<<"Index out of range.";
        	return EXIT_FAILURE;
        }

        return arr[index];
	}

	void append(int number){
		if (capacity==n){
			resize(2*capacity); // Increase the array size by 2x
		}

		arr[n] = number;
		n += 1;
	}

private:
	int *create_array(int capacity){
		return new int(capacity);
	}


	void resize(int new_capacity){
       int *b = create_array(new_capacity);

       for (int i = 0; i < capacity; i++)
       {
       	 b[i] = arr[i];
       }

       arr = b;
       capacity = new_capacity;
	}
	
};


int main(int argc, char const *argv[])
{
	DynamicArray dynamicArray;

	dynamicArray.append(1);
	dynamicArray.append(2);
	dynamicArray.append(3);
	dynamicArray.append(4);
	dynamicArray.append(5);


	for (int i = 0; i < dynamicArray.size(); i++)
	{
		cout<<dynamicArray.getitem(i)<<endl;
	}
	return 0;
}