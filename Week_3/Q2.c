#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
	for(int k=0;k<4;k++)
	{	
		char str[26],pat[26];
		scanf("%s",str);
		scanf("%s",pat);
		
		int count=0,flag=0,opcount=0;
		if(strlen(pat)<=strlen(str))
		{	
			for(int i=0;i<=strlen(str)-strlen(pat);i++)
			{
				count=0;
				for(int j=0;j<strlen(pat);j++)
				{
					opcount++;
					if(str[j+i]==pat[j])
					{
						count++;
						if(count==strlen(pat))
							break;
					}
					else
						break;
				}
				if(count==strlen(pat))
				{
					flag=1;
					break;
				}
			}
		}
		printf("%d ",strlen(pat));
		printf("%d\n",opcount);
		//if(flag)
		//	printf("FOUND\n");
		//else
		//	printf("NOT FOUND\n");
		
	}
}