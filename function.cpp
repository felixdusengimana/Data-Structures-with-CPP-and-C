#include <iostream>
using namespace std;

int functionOne(int x, int y) 
{ 
return functionTwo(5);
}

int functionTwo(int i) 
{ 
return (i*i);
}

int main(int argc, char const *argv[])
{
	cout<<functionOne(4, 6)<<endl;
	return 0;
}