#include<stdio.h>
#include<stdlib.h>
#define N_ELEMENTS 1
#define MAX_LEN_NAME 15

/*Struct to hold the chemical elements info
*/typedef struct element 
{
    char name[MAX_LEN_NAME]; 
    char symbol[3]; 
    float weight;
} element;

/*List struct for the elements*/
typedef struct listed_element{ 
    element element; 
    struct listed_element *next_element;
} listed_element;

/*Function that asks the info about 
the element and saves the data into
a list.*/
listed_element* create_element()
{
    listed_element *head;

    head = malloc(sizeof(listed_element));
    printf("\nEnter an chemical element:\n");
    printf("%25s", "name: ");
    scanf("%s", head->element.name);
    printf("%25s", "symbol: ");
    scanf("%s", head->element.symbol);
    printf("%25s", "atomic weight [ua]: ");
    scanf("%f", &(head->element.weight));
    head->next_element = NULL;
    
    return head;
}

/*Function that  creates the list of elements*/
listed_element* create_list(int n_elements)
{
    int i;
    listed_element *head, *tail;

    head = create_element();
    tail = head;
    
    for (i=0; i < n_elements-1; i++)
    {
       tail->next_element = create_element();
       tail = tail->next_element;
    }

    return head;
}


/*Function that prints the elements of the list
recursively.*/
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

/*Function that prints the element table
in a formatted fashion.*/
void print_table(listed_element* list)
{
    int i;
    printf("\n\n#============================================#\n");
    printf("%15s%15s%15s\n","name", "symbol", "weigth");
    printf("#============================================#\n");
    print_list(list);
}

int main()
{   
    int n_elements;
    listed_element* mendleev;

    printf("How many elements do you wanna enter: ");
    scanf("%d", &n_elements);
    mendleev = create_list(n_elements);
    print_table(mendleev);
}
