#include <stdio.h>
#include <stdlib.h>

// Define node of the tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right; 
} NODE;

// Define tree as a node pointer 
typedef NODE* BTREE;

// Function to print array
void print_array(int array[], int size){
    int i;
    printf("array = [");

    for (i=0;i<size;i++){
        printf(" %d", array[i]);
        putchar((i==(size-1)? ']':','));
    }
    putchar('\n');
}

// Function to build array using number from a file 
void build_array(int **array, FILE* ifp, int *size){
    
    int i;
    
    fscanf(ifp, "%d", size);
    *array = calloc(sizeof(int), *size);
    
    for (i=0; i< (*size); i++){
        fscanf(ifp, "%d", *(array) + i );
    }
    //print_array(*array, (*size));
}

// Create a node of the tree
BTREE create_node(int data, BTREE pleft, BTREE pright){
    BTREE tree=malloc(sizeof(NODE));
    tree->data = data;
    tree->left = pleft;
    tree->right = pright;
    return tree;
}

// Create a tree recursively
BTREE create_tree(int array[], int i, int size){
    //printf("Hello i=%d, size=%d, 2*i+1=%d, 2*i+2=%d\n", i, size, 2*i+1, 2*i+2);
    if(i < size){
        //printf("%d\n", i);   
        return (
            create_node(
                array[i],
                create_tree(array, 2*i + 1, size),
                create_tree(array, 2*i + 2, size)
            )
        );
    }
    else
        return  NULL;
}

//Function to print the tree inorder
void print_tree_inorder(BTREE tree){
    if (tree!=NULL){
        print_tree_inorder(tree->left);
        printf(" %d ", tree->data);
        print_tree_inorder(tree->right);
    }
}


int main(int argc, char *argv[]){
    
    int *array, size;
    FILE* ifp;
    BTREE my_tree;
    
    if (argc != 2){
        printf("Need to pass a file  with the inputs\n");
        exit(1);
    }

    ifp = fopen(argv[1], "r");
    build_array(&array, ifp, &size);
    fclose(ifp);

    print_array(array, size);

    my_tree = create_tree(array, 0, size);

    printf("tree inorder =");
    print_tree_inorder(my_tree);
    putchar('\n');

    return 0;
}
