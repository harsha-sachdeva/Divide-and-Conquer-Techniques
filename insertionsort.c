#include <stdio.h>
int main(int argc,char *argv[])
{
FILE *fs,*ft;
int arr[10];
int i,j,l,k=0,num;
int temp;
 if(argc!=3)
 {
  printf("invalid arg");
 }
 fs=fopen(argv[1],"r");
 if(fs==NULL)
 {
 
  printf("\nfile not found");
 }


while((fscanf(fs,"%d",&arr[k]))==1)
{
k++;
}

num=k-1;


ft=fopen(argv[2],"w");


for(i=0;i<=num;i++)
	{
	temp=arr[i];
		for(j=i-1;j>=0;j--)
		{
			if(arr[j]>temp)
			arr[j+1]=arr[j];
			else
			break;
			
		}
		arr[j+1]=temp;
		for (l=0;l<=num;l++)
		{
		fprintf(ft,"%d ",arr[l]);
		}
		fprintf(ft,"\n");
		
	
	}

 fclose(fs);
fclose(ft);
 return 0;
}