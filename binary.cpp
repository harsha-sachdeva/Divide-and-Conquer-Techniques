#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
void BinarySearch(int A[],int,int,int);
int count;
ofstream of;
int main(int argc, char* argv[])
{
	int A[1000],n,p=1,i,j,temp;
	char cNum[1000];
	ifstream infile;
	infile.open (argv[1]);
	ifstream read2(argv[1]);
	while (infile.good())
	{
		infile.getline(cNum, 256, ',');
                A[p]= atoi(cNum) ;
        	p++ ;
        }

	n=p-1;
	for(i=1;i<=n;i++)
        {
                for(j=i+1;j<=n;j++)
                {
                        if(A[j]<A[i])
                        {
                                temp=A[i];
                                A[i]=A[j];
                                A[j]=temp;
                        }
                }
        }

	infile.close();
	int counter=0,o=0;
	string my_string;
	of.open(argv[2]);
	while (getline(read2, my_string, '\n')) //reading the second line 		then 3rd then 4th and so on
        {
                if(counter!=0)
		{
			count=0;
			o=atoi(my_string.c_str());
			BinarySearch(A,1,n,o);
		}
		counter++;
        }
	return 0;
}

void BinarySearch(int *A,int start, int end, int key)
{
	int middle;
	middle=(start+end)/2;
	if(start<=end)
	{
		if(key==A[middle])
		{
			if(start!=end)
			count++;
			of<<key<<" found at position "<<middle<<" after "<<count<<" comparisons\n";
			return;
		}
		else if(key>A[middle])
		{
			if(start!=end)
			count++;
			start=middle+1;
			BinarySearch(A,start,end,key);
		}
		else
		{
			if(start!=end)
			count++;
			end=middle-1;
			BinarySearch(A,start,end,key);
		}
	}
	else
		of<<key<<" not found"<<"\n";
}
