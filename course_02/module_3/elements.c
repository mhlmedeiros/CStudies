#include<stdio.h>
#include<stdlib.h>
#define N_ELEMENTS 3
#define MAX_LEN_NAME 15

typedef struct element 
{
    char name[MAX_LEN_NAME]; 
    char symbol[3]; 
    float weight;
} element;

typedef struct listed_element
{
    element element;
    struct listed_element * next_element;
} listed_element;


listed_element* create_element(listed_element* head)
{
    head = malloc(sizeof(listed_element));
    printf("Enter an chemical element:\n");
    printf("\tname: ");
    scanf("%s", head->element.name);
    printf("\tsymbol: ");
    scanf(" %s", head->element.symbol);
    printf("\tatomic weight [ua]: ");
    scanf("%f", &(head->element.weight));

    return head;
}


listed_element* create_list()
{
    int i;
    listed_element *head, *tail;

    head = create_element(head);
    head->next_element = tail;

    for (i=0; i < N_ELEMENTS-1; i++)
    {
       tail = create_element(tail);
       tail = tail->next_element; 
    }
    tail = NULL;
    return head;
}



void print_list(listed_element* list)
{
    if (list != NULL)
    {
        printf("%15s%15s%15f\n", 
            list->element.name, 
            list->element.symbol,
            list->element.weight
        );
        print_list(list->next_element);
    }
}

void print_table(listed_element* list)
{
    int i;
    printf("#============================================#\n");
    printf("%15s%15s%15s\n","name", "symbol", "weigth");
    printf("#============================================#\n");
    for (i=0; i<N_ELEMENTS; i++){
        print_list(list);
    }
}

int main()
{
    //element H = {"Hydrogen", 'H', 1.00001};
    listed_element* mendleev;

    mendleev = create_list();

    //mendleev->element = H;
    //mendleev->next_element=NULL;

    //mendleev->next_element=NULL;

    print_table(mendleev);
}
