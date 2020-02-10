#include <stdio.h>
#include <stdlib.h>
int min(int a,int b)
{
	return (a<b)?a:b;
}
void main()
{
	int a,b,t,gcd,count;
	for(int i=0;i<5;i++)
	{	
		count=0;
		scanf("%d%d",&a,&b);
		for(t=min(a,b); ;t--)
		{	
			count++;
			if((a%t==0) && (b%t==0))
			{
				gcd=t;
				break;
			}
		}
		printf("%d\t",a+b);
		printf("%d\t",count );
		printf("%d\n",gcd);
	}
}