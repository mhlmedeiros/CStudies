#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


typedef struct list {int data; struct list *next;} list; // actually this is an element of a (linked) list

int is_empty(const list *l){return (l==NULL);}

void print_list(list *h, char *title){
    printf("%s\n", title);
    while (h != NULL){
        printf("%d : ", h -> data);
        h = h -> next;
    }
    putchar('\n');
}


void print_elements(list *h){
    if (h != NULL){
        printf("%d : ", h -> data);
        print_elements(h->next);
    }
    else putchar('\n');
}

void print_list_recursive(list *h, char *title){
    printf("%s\n", title);
    print_elements(h);    
}


int main(){
    list list_of_int;
    list *head = NULL;

    head = malloc(sizeof(list));
    printf("sizeof(list) = %lu \n", sizeof(list));

    head -> data = 5;
    head -> next = NULL;

    print_list_recursive(head, "single element list");
    return 0;

}