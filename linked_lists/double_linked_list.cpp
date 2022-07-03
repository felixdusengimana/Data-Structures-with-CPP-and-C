#include <iostream>
#include <malloc.h>
using namespace std;

struct Node
{
	int data;
    struct Node *next;
    struct Node *previous;
};

struct Node *head, *tail = NULL;
struct Node *insert_at_end(struct Node *);
struct Node *insert_at_start(struct Node *);
struct Node *read_from_start(struct Node *);
struct Node *read_from_end(struct Node *);

int main()
{
	int choice;
	do{
      cout<<"\n1. Insert at end";
      cout<<"\n2. Insert at beginning";
      cout<<"\n3. Read from beginning";
      cout<<"\n4. Read from end";
      cout<<"\n0. Exit";
	  cout<<"\n\nEnter your choice : ";
      cin>>choice;

      switch(choice){
      	case 1:
      		tail = insert_at_end(tail);
      	break;

      	case 2:
      		head = insert_at_start(head);
      	break;

      	case 3:
      		head = read_from_start(head);
      	break;

      	case 4:
      		tail = read_from_end(tail);
      	break;

      	default:
      		cout<<"\nNo choice available.";
      	break;
      }
	}while(choice!=0);


	return 0;
}

struct Node * create_node(char s, struct Node * node){
  	struct Node *new_node, *ptr;
	int num;
	cout<<"\n Enter -1 to end";
	cout<<"\n Enter the data :";
	cout>>num;

	if(s == "t"){
    
    while(num != -1){
    	new_node = (struct node*)malloc(sizeof(struct node));
    	new_node -> data = num;
    	if(node == NULL){
    		new_node -> next = NULL;
    		new_node -> previous = NULL;
			node = new_node;
    	}else{
    		ptr = node;
    		while(ptr -> next != NULL)
    			ptr = ptr -> next;
    		ptr -> next = new_node;
			new_node -> next = NULL;
			new_node -> previous = ptr;
			node = new_node;
    	}
    	cout<<"\n Enter the data : ";
		cin>>num;
    }

	return node;

	}else{
    while(num != -1){
    	new_node = (struct node*)malloc(sizeof(struct node));
    	new_node -> data = num;
    	if(node == NULL){
    		new_node -> next = NULL;
    		new_node -> previous = NULL;
			node = new_node;
    	}else{
    		ptr = node;
    		while(ptr -> previous != NULL)
    			ptr = ptr -> previous;
    		ptr -> previous = new_node;
    		new_node -> next = ptr;
    		new_node -> previous = NULL;
    		node = new_node;
    	}
    	cout<<"\n Enter the data : ";
		cin>>num;
    }

	return node;
	}
}

struct Node *insert_at_end(struct Node *tail){
	if(tail == NULL){
		tail = create_node('t', tail);	
    }
  return 0;
} 
struct Node *insert_at_start(struct Node *head){
  return 0;
}
struct Node *read_from_start(struct Node *head){
  return 0;
}
struct Node *read_from_end(struct Node *tail){
  return 0;
}