#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <sys/time.h>
#include <fstream>
#include <math.h>
 
using namespace std;
 
int* b;
bool odd;
bool enablePrinting=false;
 
//Insertion Sort
void insertionSort(int* a, int size)
{
    for (int i = 1;i < size;i++)
    {
        int x = a[i];
        int j = i;
        while (j > 0 && a[j-1] > a[j])
        {
            int temporaryVariable=a[j];
            a[j] = a[j-1];
            a[j-1]=temporaryVariable;
            j --;
        }
        a[j] = x;
    }
}
/////////////////////////////
//Merge Sort
void merge(int* a, int first, int middle, int last)
{
    int j,i0,i1;
    i0 = first;
    i1 = middle;
 
    // While there are elements in the left or right runs
     
    for (j = first; j < last; j++) {
        // If left run head exists and is <= existing right run head.
        if (i0 < middle && (i1 >= last || a[i0] <= a[i1])){
            b[j] = a[i0];
            i0++;
        }
        else{
            b[j] = a[i1];
            i1++;
        }
    } 
     
}
void copyArray(int* a,int* b, int first, int last)
{
    for(int k = first; k < last; k++)
        a[k] = b[k];
}
void split(int* a, int first, int last)
{
     
    if (last - first<2)
        return;
    int middle = floor((first + last) / 2);
    //cout<<first<<" "<<middle<<" "<<last<<endl;
    split(a, first, middle);
    split(a, middle, last);
    merge(a, first, middle, last);
    copyArray(a,b, first, last);
}
 
/////////////////////////////
int* populateArray(int size)
{
    b=new int[size];
    int* a = new int[size];
    for (int i = 0;i < size;i++)
    {
        srand(rand()*i);
        a[i] = rand() % 100;
        b[i]=-1;
    }
    return a;
}
void printArray(int* a,int size)
{
    for (int i = 0;i < size;i++)
    {
        if(enablePrinting)
            cout<<a[i]<<"  ";
    }
    if(enablePrinting)
        cout<<endl;
}
long long now()
{
    //LINUX ONLY.
    struct timeval timeNow;
    gettimeofday(&timeNow, NULL);
    return (timeNow.tv_sec * 1000000 + timeNow.tv_usec);
}
int diff(timespec end, timespec start)
{
    timespec temp;
    if ((end.tv_nsec-start.tv_nsec)<0) {
        temp.tv_sec = end.tv_sec-start.tv_sec-1;
        temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
    } else {
        temp.tv_sec = end.tv_sec-start.tv_sec;
        temp.tv_nsec = end.tv_nsec-start.tv_nsec;
    }
    return temp.tv_sec;
}
 
int main()
{
    int sizes[10] ={100, 1000, 10000, 100000};
 
    long long start, end;
 
    ofstream CFile ("comparison.csv"); 
    CFile<<"SIZE;Insertion;Merge"<<endl;
      
    for (int i = 0;i < 4;i++)
    {
        int size = sizes[i];
         
        //long long selectionSortTimeSum = 0;    
        long long insertionSortTimeSum = 0;
        long long mergeSortTimeSum = 0;
         
        for (int j = 0;j < 1;j++)
        {
             int* a = populateArray(size);           
            //==Merge==//
            a = populateArray(size);
            start = now();
            split(a, 0, size);
            printArray(a,size);
            //NOW LIST IS SORTED ON THE 2ND HALF OF A
            end = now();
            mergeSortTimeSum = end- start;
            //==Insertion==//
            a = populateArray(size);
            start = now();
            insertionSort(a, size);
            printArray(a,size);
            end = now();
            insertionSortTimeSum = end- start;
             
             
        }
        cout << "Insertion " << size << " : " << insertionSortTimeSum << endl;
        cout << "Merge     " << size << " : " << mergeSortTimeSum << endl;
        CFile<<size<<";"<<insertionSortTimeSum<<";"<<mergeSortTimeSum<<endl;
         
    }
    return 0 ;
}
