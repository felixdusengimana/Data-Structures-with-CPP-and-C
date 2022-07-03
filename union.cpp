#include <iostream>
using namespace std;

union infoHere{
	int a;
	char name;
};

int main(int argc, char const *argv[])
{
	union infoHere data;
	data.a = 19;
	data.name = 'a';
	cout<<data.a<<endl;
	cout<<data.name<<endl;
	return 0;
}