#include <iostream>
#include <malloc.h>

using namespace std;
struct node
{
   int data;
   struct node *next;
};

struct node *start = NULL;
struct node *create_linkedlist(struct node *);
struct node *display(struct node *);

int main()
{

	int choice;
	do{
    cout<< "\n1. Create a list";
	cout<<"\n2. Display the list";
	cout<<"\n3. Exit the list";
	cout<<"\n\nEnter your choice : ";
    cin>>choice;

    switch(choice){
    	case 1:
    	start = create_linkedlist(start);
    	printf("\n Linked List Created Successfully");
    	break;
    	case 2:
    	start = display(start);
    	break;
    }

	}while(choice != 3);
	return 0;
}

struct node *create_linkedlist(struct node *start)
{
	struct node *new_node, *ptr;
	int num;
	cout<<"\n Enter -1 to end";
	cout<<"\n Enter the data :";
	cin>>num;
    
    while(num != -1){
    	new_node = (struct node*)malloc(sizeof(struct node));
    	new_node -> data = num;
    	if(start == NULL){
    		new_node -> next = NULL;
			start = new_node;
    	}else{
    		ptr = start;
    		while(ptr -> next != NULL)
    			ptr = ptr -> next;
    		ptr -> next = new_node;
			new_node -> next = NULL;
    	}
    	cout<<"\n Enter the data : ";
		cin>>num;
    }

	return start;
}

struct node *display(struct node *start){
	struct node *ptr;
	ptr = start;
	while(ptr != NULL)
	{
		cout<<ptr -> data;
		ptr = ptr -> next;
	}
	return start;
}