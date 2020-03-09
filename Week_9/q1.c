#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int Table[27],n,m,count=0;
void shiftTable(char P[])
{
	for(int i=0;i<27;i++)
		Table[i]=m;
	for(int j=0;j<m-1;j++)
	{
		int ch=P[j]-96;
		Table[ch]=m-1-j;
	}
}
int Match(char T[],char P[])
{
	int i;
	n=strlen(T);
	m=strlen(P);
	i=m-1;
	shiftTable(P);
	while(i<=n-1)
	{
		int k=0;
		while(k<m)
		{
			count++;
			if(T[i-k]==P[m-1-k])
				k++;
			else
				break;
		}
		if(k==m)
			return i-m+1;
		else
		{
			int ch=T[i]-96;
			i=i+Table[ch];
		}
	}
	return -1;
}

void main()
{
	int pos;
	char T[100],P[100];
	printf("Enter string\n");
	scanf("%s",T);
	printf("Enter pattern to match\n");
	scanf("%s",P);
	pos=Match(T,P);
	if(pos!=-1)
		printf("Found at pos %d\n",pos );
	else
		printf("NOT FOUND!!\n");
	printf("count = %d\n",count );
}