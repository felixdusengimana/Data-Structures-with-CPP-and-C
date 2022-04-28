#include <iostream>
using namespace std;

int MAX_SIZE = 10;


class Stack
{
public:
    int * stack = new int[MAX_SIZE];
    int top = -1;

	void push(int elem){
      if(top >= (MAX_SIZE-1)){
      	cout<<"Stack is full."<<endl;
      }else{
      	cout<<"The dded element is "<< elem <<endl;
      	stack[++top] = elem;
      }
	}

	int pop(){
		if (top<0){
          	cout<<"Stack is empty.";
			return EXIT_FAILURE;
		}else{
        	cout<<"The popped element is "<< stack[top--] <<endl;
		}
		return 0;
	}

	int peek(){

		if(top<0){
			cout<<"Stack is empty.";
			return EXIT_FAILURE;
		}

		return stack[top];
	}

	int isEmpty(){
		return (top < 0);
	}

	
};


int main(int argc, char const *argv[])
{
	Stack stack;

    stack.push(1);
    stack.push(2);

    cout<<stack.peek()<<endl;
    
    stack.pop();
    cout<<stack.peek()<<endl;

    stack.pop();
    cout<<stack.peek()<<endl;

	return 0;
}