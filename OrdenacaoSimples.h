#include <cmath>
#include <climits>
#include <iostream>

using namespace std;

template<typename T>
void Swap_values(T *n1, T *n2)
{
    T aux;
    aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}


template<typename T>
void Bublesort_ND(T vetor[], int tam)
{
    for(int i = tam - 2 ; i >= 0 ; i--)
    {
        for(int j = 0 ; j <= i ; j++)
        {
            if(vetor[j] > vetor[j + 1])
            {
                Swap_values(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}


template<typename T>
void Selectionsort_ND(T vetor[], int tam)
{
    int minimun;
    for (int i = 0 ; i < tam - 1 ; i++)
    {
        minimun = i;
        for (int j = i + 1 ; j < tam ; j++)
        {
            if (vetor[j] < vetor[minimun])
            {
                minimun = j;
            }
        }
        Swap_values(&vetor[i], &vetor[minimun]);
    }
}


template<typename T>
void Insertionsort_ND(T vetor[], int tam)
{
    int j;
    T x;
    for (int i = 1 ; i < tam ; i++)
    {
        x = vetor[i];
        j = i - 1;
        //vetor[0] = x;
        while (x < vetor[j] && j >= 0)
        {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = x;
    }
}


template<typename T>
int Particao(T A[], int p, int r)
{
    int i, j;
    T x, temp;

    // pivô
    x = A[p];

    //temp = A[r + 1];

    //A[r + 1] = x;
    i = p - 1;
    j = r + 1;

    while(true)
    {
        do{i++;} while(A[i] < x);

        do{j--;} while(A[j] > x);


        if(i >= j)
        {
            return j;
        }

        Swap_values(&A[i], &A[j]);

    }
}
template<typename T>
void Quicksort(T A[], int p, int r)
{
    int q;
    if(p < r)
    {
        q = Particao(A, p, r);
        Quicksort(A, p, q);
        Quicksort(A, q + 1, r);
    }
}


template<typename T>
void Merge(T A[], int p, int q, int r)
{
    int a, b, i, j;

    a = q - p + 1;  //esquerda
    b = r - q;  //direita

    T esq[a + 1], dir[b + 1];

    for(i = 0 ; i < a ; i++)
    {
        esq[i] = A[p + i];
    }
    for(j = 0 ; j < b ; j++)
    {
        dir[j] = A[q + j + 1];
    }
    esq[a] = CHAR_MAX;
    dir[b] = CHAR_MAX;
    i = 0;
    j = 0;
    for(int k = p ; k <= r ; k++)
    {
        if(esq[i] <= dir[j])
        {
            A[k] = esq[i];
            i++;
        }
        else
        {
            A[k] = dir[j];
            j++;
        }
    }
}
template<typename T>
void Mergesort_ND(T A[], int p, int r)
{
    int q;
    if(p < r)
    {
        q = floor((p + r) / 2);
        Mergesort_ND(A, p, q);
        Mergesort_ND(A, q + 1, r);
        Merge(A, p, q, r);
    }
}


int Pai(int i)
{
    return floor(i/2);
}
int Esq(int i)
{
    return 2*i;
}
int Dir(int i)
{
    return 2*i + 1;
}
template<typename T>
void Heapfica_ND(T A[], int i, int tamHeap)
{
    int l = Esq(i), r = Dir(i), maior;

    if(l <= tamHeap && A[l] > A[i])
    {
        maior = l;
    }
    else
    {
        maior = i;
    }
    if(r <= tamHeap && A[r] > A[maior])
    {
        maior = r;
    }
    if(maior != i)
    {
        Swap_values(&A[i], &A[maior]);
        Heapfica_ND(A, maior, tamHeap);
    }
}
template<typename T>
void Constroi_Heap(T A[], int tamHeap)
{
    for(int i = floor(tamHeap/2) ; i >= 0 ; i--)
    {
        Heapfica_ND(A, i, tamHeap);
    }
}
template<typename T>
void Heapsort(T A[], int tamHeap)
{
    Constroi_Heap(A, tamHeap);
    for(int i = tamHeap ; i > 0 ; i--)
    {
        Swap_values(&A[0], &A[i]);
        tamHeap--;
        Heapfica_ND(A, 0, tamHeap);
    }
}


template<typename T>
void Shellsort_ND(T A[], int tam)
{
    int h = 1, j;

    while(h < tam/3)
    {
        h = 3*h + 1;
    }
    while(h >= 1)
    {
        for(int i = h ; i < tam ; i++)
        {
            j = i;
            while(j >= h && A[j] < A[j-h])
            {
                Swap_values(&A[j], &A[j-h]);
                j = j-h;
            }
        }
        h = h/3;
    }
}



void Countingsort_ND(int A[], int B[], int k, int tam)
{
    int C[k + 1];
    int i;
    for(i = 0 ; i <= k ; i++)
    {
        C[i] = 0;
    }
    for(i = 1 ; i <= tam ; i++)
    {
        C[A[i]] = C[A[i]] + 1;
    }
    for(i = 1 ; i <= k ; i++)
    {
        C[i] = C[i] + C[i - 1];
    }
    for(i = tam ; i >= 1 ; i--)
    {
        B[C[A[i]]] = A[i];
        C[A[i]] = C[A[i]] - 1;
    }
}
