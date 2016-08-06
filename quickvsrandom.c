#include <stdio.h>
#include <stdlib.h>
 
//void swap(int *x,int *y);
int choose_pivot(int i,int j );
void quicksort(int list[],int m,int n);
void display(int list[],const int n);
 static int q_count=0,rq_count=0;

void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 


int partion(int arr[], int p, int r)
{
    int pivotIndex = p + rand()%(r - p + 1); //generates a random number as a pivot
    int pivot;
    int i = p - 1;
    int j;
    pivot = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[r]);
//1
rq_count++;
    for (j = p; j < r; j++)
    {   
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
//2
	    rq_count++;
        }
 
    }
    swap(&arr[i+1], &arr[r]);
//3
    rq_count++;
    return i + 1;
}
 
void rquick_sort(int arr[], int p, int q)
{
    int j;
    if (p < q)
    {
        j = partion(arr, p, q);
        rquick_sort(arr, p, j-1);
        rquick_sort(arr, j+1, q);
    }
}


int main()
{
    const int SIZE = 10;
    int list[SIZE],list2[SIZE];
 
    int i = 0;
 
    /* generates random numbers and fill the list */
    for(i = 0; i < SIZE; i++ )
        list[i] = rand()%(10+1-0)+0; //rand()%(max_no.+1-min_no)+min_no.

     for(i=0;i<SIZE;i++)
     {
     	list2[i]=list[i];
     }

    printf("The list before sorting is:\n");
    display(list,SIZE);
 
    /* sort the list using quicksort algorithm */
    quicksort(list,0,SIZE-1);
 
    printf("\nThe list after sorting with quick sort algorithm:\n");
    display(list,SIZE);

    //printf("\nNo. of comparison in quick sort algo: %d\n",q_count);

    /* sort the list using randomized quick sort algorithm */
    rquick_sort(list2,0,SIZE-1);

    printf("\nThe list after sorting with randomized quick sort algorithm:\n");
    display(list2,SIZE);

//q_count
printf("\nNo. of echanges in quick sort algo: %d\n",q_count);
    printf("\nNo. of echanges in randomized quick sort algo: %d\n",rq_count);
    return 1;
}
 

int choose_pivot(int i,int j )
{
    return((i+j) /2);
}
 
void quicksort(int list[],int m,int n)
{
    int key,i,j,k;
    if( m < n)
    {
        k = choose_pivot(m,n);
        swap(&list[m],&list[k]);
	q_count++;

        key = list[m];
        i = m+1;
        j = n;
        while(i <= j)
        {
			//q_count++;
            while((i <= n) && (list[i] <= key))
                i++;
            while((j >= m) && (list[j] > key))
                j--;
            if( i < j)
		{
                	swap(&list[i],&list[j]);
			q_count++;
		}
        }
        /* swap two elements */
        swap(&list[m],&list[j]);
	q_count++;
 
        /* recursively sort the lesser list */
        quicksort(list,m,j-1);
        quicksort(list,j+1,n);
    }
}
void display(int list[],const int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d\t",list[i]);
}
