/*
Implementation of a doubly linked
list that hold random generated integers
and keep only the distinct numbers.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE_LIST 200

struct node { int data; struct node* prev; struct node* next;};
typedef struct node Node;

/* 
creates a node with links to previous and next node
intially pointing to NULL and with a data member with a
random integer in it.
*/
Node* create_node(){
    int number;
    Node* node = malloc(sizeof(Node));
    number = rand()%50;

    node->data = number;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

/*
adds a new node in sequency of nodes
*/
Node* add_node(Node* head)
{
    Node *new_node = create_node();
    head->next = new_node;
    new_node->prev = head;
    return new_node;
}

/*
Prints lists in lines with 10 numbers
*/
void print_list(Node* head)
{   
    int count=0;
    while (head!=NULL){
        printf("%3d", head->data);
        count++;
        putchar((count%10==0)?'\n':' ');
        head = head->next;
    }
    putchar('\n');
}

/*
Creates the list with SIZE_LIST nodes
*/
Node* create_list()
{
    int i;
    Node* head = create_node();
    Node* tail;

    tail = head;
    for (i=0; i< SIZE_LIST-1; i++){
        tail = add_node(tail);
    }
    return head;
}

/*
Deletes a node
*/
Node* delete_node(Node* head)
{
    Node *next = head->next;
    if (next!=NULL){
        head->prev->next = head->next;
        head->next->prev = head->prev;
    }
    else
        head->prev->next=NULL;
    free(head);
    return next;
}

/*
Removes nodes with the same number of the head
*/
void remove_duplicates(Node* head)
{
    int test_number;
    Node* tail;

    tail = head->next;
    test_number = head->data;

    while (tail!=NULL)
    {
        if(tail->data == test_number)
            tail = delete_node(tail);
        else
            tail = tail->next;
    }
}

/*
Removes all duplicated nodes of the list;
*/
void remove_all_duplicates(Node* head)
{
    while (head!=NULL)
    {
        remove_duplicates(head);
        head = head->next;
    }
}


int main(void)
{   
    srand(time(NULL));
    Node* head;
    head = create_list();
    printf("%s","************ ORIGINAL LIST ************\n");
    print_list(head);
    printf("\n\n");

    printf("%s","*********** LIST OF DISTINCT **********\n");
    remove_all_duplicates(head);
    print_list(head);

}
