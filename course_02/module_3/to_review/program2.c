#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a node for the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a new node at the end of the linked list
void insert(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref; // Used in step 5
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
}

// Function to bubble sort the linked list
void bubbleSort(struct Node *head)
{
    int swapped, i;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Function to print the linked list
void printList(struct Node *node)
{
    int count = 0;
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
        count++;
        if (count % 5 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    // Seed the random number generator
    srand(time(0));

    // Insert 100 random integers into the linked list
    for (int i = 0; i < 100; i++)
    {
        int random_value = rand() % 1000; // Random integers between 0 and 999
        insert(&head, random_value);
    }

    // Print the unsorted list
    printf("Unsorted List:\n");
    printList(head);

    // Sort the list
    bubbleSort(head);

    // Print the sorted list
    printf("\nSorted List:\n");
    printList(head);

    return 0;
}
