#include <stdio.h>
#include <stdlib.h> // to use exit()


void print_file(FILE *ifp)
{
    char c;
    
    fscanf(ifp, "%c", &c);
    while ((c = getc(ifp)) != EOF){
        putchar(c);
    }
}

void double_space(FILE *ifp, FILE *ofp)
{
    char c;
    rewind(ifp);
    while ((c=getc(ifp)) != EOF)
    {
        putc(c, ofp);
        if (c=='\n')
            putc('\n', ofp);
    }

}


int main(int argc, char *argv[]){

    FILE *ifp, *ofp;

    if (argc != 3){
        printf("Need executable inputfile outputfile\n");
        exit(1);
    }

    ifp = fopen(argv[1], "r+");
    ofp = fopen(argv[2], "w+");

    printf("my %s file as read is \n\n", argv[1]);
    print_file(ifp);
    double_space(ifp, ofp);
    fclose(ifp);
    fclose(ofp);

}