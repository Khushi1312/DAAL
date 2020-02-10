#include<stdio.h>
#include<stdlib.h>
#define FACT 1024

typedef struct 
{	
	int size;
	int factor[FACT+1];
	int power[FACT+1];
}FACTORS;

int getFactors(int x,FACTORS* factors)
{
	int n = x,c = 0;
	int k = 1;

	int count = 0;

	factors->factor[0] = 1;
	factors->power[0] = 1;

	for(int i = 2;i<=n;i++)
	{
		count++;
		c = 0;

		while(n%i == 0)
		{
			count++;
			c++;
			n = n/i;
		}

		if(c>0)
		{
			factors->power[k] = c;
			factors->factor[k] = i;
			k++;
		}
	}

	factors->size = k-1;
	return count;
}

void getGCD(int m,int n)
{
	FACTORS mfact,nfact;

	int result = 1;

	int count1 = getFactors(m,&mfact);
	int count2 = getFactors(n,&nfact);

	int count3 = 0;

	int min,i = 1,j = 1;

	while(i<=mfact.size && j<=nfact.size)
	{
		count3++;
		if(mfact.factor[i]<nfact.factor[j])
			i++;

		else if(mfact.factor[i]>nfact.factor[j])
			j++;

		else
		{
			min = (mfact.power[i]>nfact.power[j])?nfact.power[j]:mfact.power[i];
			result = result * min * mfact.factor[i];
			i++;
			j++;

		}
	}
	printf("\n%d  %d\n",(m+n),(count1+count2+count3));
}

int main()
{
	int a,b;
	for(int i = 0;i<4;i++)
	{
		scanf("%d %d",&a,&b);
		getGCD(a,b);
		printf("\n");
	}

	return 0;
}