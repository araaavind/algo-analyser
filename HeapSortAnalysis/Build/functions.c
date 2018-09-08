#include<stdio.h>
void maxHeapify(int A[], int n, int i)
{
    int largest;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    if(l < n && A[l] > A[i])
    {
        if(A[l] > A[r])
            largest = l;
        else
        {
            if(r < n && A[r] > A[i])
                largest = r;
            else
                largest = l;
        }
    }
    else if(r < n && A[r] > A[i])
        largest = r;
    else
        largest = i;
    
    if( largest != i)
    {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        maxHeapify(A, n, largest);
    }
}

void buildHeap(int A[], int n)
{
    for(int c = n/2 - 1; c >= 0; c--)
        maxHeapify(A, n, c);
}

void heap_sort(int A[], int n)
{
    buildHeap(A, n);
    int length = n;
    for(int c = length - 1; c > 0; c--)
    {
        int temp = A[0];
        A[0] = A[c];
        A[c] = temp;
        n--;
        maxHeapify(A, n, 0);
    }
}
