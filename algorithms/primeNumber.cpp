#include <iostream>
using namespace std;

int main()
{
	int number = 0;
    cout<<"Enter the number:: ";
    cin>>number;

	if (number<=1){
      cout<<number<<" is not a Prime number.\n";
	}

	for (int i = 2; i <= (number/2); i++)
	{
		if((number%i)==0){
      		cout<<number<<" is not a Prime number.\n";
			return 0;
		}
	}

	cout<<number<<" is a Prime number.\n";

	return 0;
}