#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;



void swap(int &a, int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

int part(int array[],int start,int end)
{
	int i, j, p=array[end];
	j=start;
	for(i=start; i<=end-1;i++)
	{
		if(array[i]<=p)
		{
			swap(array[j],array[i]);
			j++;
		}
	}
	swap(array[j],array[end]);
	return j;
}

void qsort(int array[],int start,int end,int size, ofstream &out)
{
	if(end>start)
	{
		int pindex=part(array,start,end);
		for(int i=0;i<=size;i++)
		{
			if(i==pindex)
			out<<"("<<array[i]<<"),";
			else
			out<<array[i]<<",";
		}
		out<<"\n";
		qsort(array,start,pindex-1,size,out);
		qsort(array,pindex+1,end,size,out);
	}
}

int main(int argc, char**argsv)
{
	char string[10][10],ch; 
	int i=0,j=0,count,array[15];
	ifstream input;
	ofstream output;
	input.open(argsv[1]);
	output.open(argsv[2]);
	
	if(!input || !output)
	cout<<"Cannot open the input/output file";
	else
	{
			input.get(ch);
			while(!input.eof())
			{	
				if(ch!=' ')
				{
					string[j][i]=ch;
					i++;
				}
				else
				{
					string[j][i]='\0';
					j++;
					i=0;
				}
				input.get(ch);		
			}
		count=j;	
		for(i=0;i<=count;i++)
		{
			array[i]=atoi(string[i]);
			output<<array[i]<<",";
		}
		output<<"\n";
		int size=count;
		qsort(array,0,count,size,output);
		for(int i=0;i<=count;i++)
		output<<array[i]<<",";
	}
 return 0;
}
