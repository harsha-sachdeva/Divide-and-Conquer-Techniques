#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
void swap(int &a,int &b)
{
	int tmp;
	tmp=a;
	a=b;
	b=tmp;
}
int selection_sort(int array[],int size1,int position)
{
		for(int i=0;i<=size1;i++)
		{
			for(int j=i+1;j<=size1;j++)
			{
				if(array[i]>array[j])
				swap(array[i],array[j]);
			}
		}
		return array[position];		
}
int main(int argc, char**argsv)
{

	char string[10][10],ch; 
	int i=0,j=0,count,position;
	int num, array[40];
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
				
				if(ch!=' ' && ch!='\n')
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
		
			count=j-1;
			
		for(i=0;i<=count-1;i++)
		{
			array[i]=atoi(string[i]);
		}
		position=atoi(string[count]);
		num=selection_sort(array,count-1,position-1);
		output<<num;
	}
 return 0;
}
