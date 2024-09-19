#include <iostream>
using namespace std;

class graph{
public:
    graph(int N):size(N){};
    graph(double **table, int N):matrix(table), size(N){};
    void print(){
        /*for(int i=0; i < size; i++){
            for(int j=0; j< size; j++){
                cout << matrix[i][j] << ", ";
            }
            cout << endl;
        }*/
       cout << size << endl;
    };
private:
    int size;
    double **matrix;
};

int main(){
    /*Create specific undireted graph as a ADT*/
    double A[2][2];   
    graph test(2);
    cout << "OK" << endl;
    test.print();

    /*Create a random undirected graph */

    /*Implement the "is connected" algorithm */

    /*Implement the Dijsktra's algorithm */
}