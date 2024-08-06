#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct list { int data; struct list *next;} list;

int is_empty(const list *l){return (l==NULL);}

list* create_list(int d){
    list* head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    return head;
}

list* add_to_front(int d, list* h){
    list* head = create_list(d);
    head -> next = h;
    return head;
}

list* array_to_list(int* d, int size){
    list* head = create_list(d[0]);
    int i;
    for (i=1; i<size; i++){
        head = add_to_front(d[i], head);
    }
    return head;
}

void print_list(list* head, char* title){
    printf("%s\n", title);
    while (head!=NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


int main(){
    int d[6] = {2,4,5,6,9,1};
    list* l;

    l = array_to_list(d, 6);
    print_list(l, "array to list");
}