# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int main(int argc,char * argv[])
{
int maximum,minimum,n,i=0,arr[20];
int j;
char *st= argv[1];
char* d=argv[2];
const char e[3] = ", ";
char *ch;
int d1;
d1=atoi(d);
ch = strtok(st,e);
while(ch!= NULL )
{
arr[i]=atoi(ch);
i++;
ch=strtok(NULL,e);
}
n=i;
minimum=arr[0];
maximum=arr[0];
for(j=0;j<n;j++)
{
if(arr[j]>maximum)
maximum=arr[j];
if(arr[j]<minimum)
minimum=arr[j];
}
if(d1==1)
printf("%d",maximum);
else if(d1==2)
printf("%d",minimum);
return 0;
}
