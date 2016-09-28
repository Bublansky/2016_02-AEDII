//#include <iostream>
//#include "OrdenacaoSimples.h"
#include "Grafo.h"
//using namespace std;

template<typename T>
void ShowArray(T A[], int tam)
{
    int i;
    for(i = 0 ; i < tam ; i++)
    {
        cout << A[i] << " ";
    }
}

int main()
{
    cout << "Hello world!" << endl;

    int tam = 10;
    int tam2 = 10;
    int C[tam] = {-1, 23, 8, 5, 2, 1, 3, 4, 3, 1};
    int B[tam] = {-1, 2, 5, 3, 0, 2, 3, 1, 0, 3};
    int E[tam] = {-1, 1, 8, 7, 6, 5, 4, 3, 2, 1};
    int D[tam] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    char A[tam] = "BCGHADEFI";

    //ShowArray(A, tam);
    cout << endl << endl;

    //Bublesort_ND(A, tam);
    //Insertionsort_ND(A, tam);
    //Selectionsort_ND(A, tam);
    //Quicksort(A, 0, tam - 1);
    //Mergesort_ND(A, 0, tam - 1);
    //Heapsort(A, tam);
    //Shellsort_ND(B, tam);
    //Countingsort_ND(E, D, 8, tam - 1);
    //ShowArray(D, tam);

	cout << endl << endl;
	cin >> tam;

    return 0;
}
