#include<stdio.h>
#include<stdlib.h>

void main()
{
    int adj[10][10],ideg[10],flag[10],v,count=0;
    printf("Enter number of vertices:");
    scanf("%d",&v);
    printf("Enter matrix\n");
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
            scanf("%d",&adj[i][j]);
    }
    
    for (int i=0;i<v;i++)
    {
        ideg[i]=0;
        flag[i]=0;
    }

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(adj[i][j]==1)
                ideg[j]++;
        }
    }

    printf("Topo Sort:\n");
     while(count<v)
     {
        for(int k=0;k<v;k++)
        {
            if((ideg[k]==0) && (flag[k]==0))
            {
                printf("%d ",k);
                flag [k]=1;
            }
            for(int i=0;i<v;i++)
            {
                if(adj[i][k]==1)
                    ideg[k]--;
            }
        }
        count++;
    }
}