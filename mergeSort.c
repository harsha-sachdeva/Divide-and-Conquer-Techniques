# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void merge(int arr[], int left, int m, int right)
{
	int i, j, k;
	int num1 = m - left + 1;
	int num2 =  right - m;
	int Left[num1], Right[num2];
	for(i = 0; i < num1; i++)
		Left[i] = arr[left + i];
	for(j = 0; j < num2; j++)
		Right[j] = arr[m + 1+ j];
	i = 0;
	j = 0;
	k = left;
	while (i < num1 && j < num2)
	{
		if (Left[i] <= Right[j])
		{
			arr[k] = Left[i];
			i++;
		}
		else
		{
			arr[k] = Right[j];
			j++;
		}
		k++;
	}
	while (i < num1)
	{
		arr[k] = Left[i];
		i++;
		k++;
	}
	while (j < num2)
	{
		arr[k] = Right[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int m = left+(right-left)/2; 
		mergeSort(arr, left, m);
		mergeSort(arr, m+1, right);
		merge(arr, left, m, right);
	}
}

void printArray(int A[], int size)
{
	int i;
	for (i=0; i < size; i++)
	printf("%d ", A[i]);
	printf("\n");
}

int main(int argc,char * argv[])
{
	int i=0,a[20];
	char *st= argv[2];
	char* d=argv[1];
	const char e[3] = ", ";
	char *ch;
	int d1;
	d1=atoi(d);
	ch = strtok(st,e);
	while(ch!= NULL )
	{
		a[i]=atoi(ch);
		i++;
		ch=strtok(NULL,e);
	}
	mergeSort(a, 0, d1-1);
	printArray(a, d1);
	return 0;
}
