#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int i = 10, j = 10;
	cout<<"i="<<i<<" & j="<<j<<endl; //10 //10
	cout<<"i="<<++i<<" & j="<<j++<<endl;//11 //10
	cout<<"i="<<i<<" & j="<<j<<endl;//11 //11
	cout<<"i="<<i--<<" & j="<<--j<<endl;//11 //10
	cout<<"i="<<i--<<" & j="<<--j<<endl;//10 //9

	int a = --i, b=j++;
	cout<<"a="<<a--<<" & b="<<--b<<endl;//8 //9
	cout<<"i="<<i<<" & j="<<j<<endl;//8 //10
	// cout<<++i++<<endl; //error
	// cout<<i<<endl;

	return 0;
}