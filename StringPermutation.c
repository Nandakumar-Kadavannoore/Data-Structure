/*To perform permutation of string */

#include<stdio.h>
#include<string.h>

void swap(char str[],int x,int y)
{
	char z=str[x];
	str[x]=str[y];
	str[y]=z;
}

void permute(char str[],int length)
{
	printf("%s\n",str);
	char x[45];
	int i=0;
	strcpy(x,str); 
	while(i>=0)
	{
		  if(i+1>=length)
		   swap(str,i,0);
		  else
		   swap(str,i,i+1);
		
		if(strcmp(x,str)==0)  
		{ break; }
		
		printf("%s\n",str);  
		
		i++;
		i=i%(length);
	}
}

int main(void)
{
	char str[56];
	int count=0,i;
	puts("\nEnter string:: ");
	gets(str);
	for(i=0;str[i]!='\0';i++)
	 count++;
    permute(str,count);
	
	return 0; 
}
