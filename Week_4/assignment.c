#include<stdio.h>
#include<stdlib.h>

int n;

int permute(int c[],int l,int r,int b[1000][n])
{
  static int row_in_b=0;

  if(l==r)
  {
    for(int i=0;i<n;i++)
    {
      b[row_in_b][i]=c[i];
    }
    row_in_b++;
  }
  else
  {
    for(int i=l;i<=r;i++)
    {
      int t=c[i];
      c[i]=c[l];
      c[l]=t;
      permute(c,l+1,r,b);
      t=c[i];
      c[i]=c[l];
      c[l]=t;
    }
  }
  return row_in_b;
}

int main()
{
  int a[1000][1000];
  printf("Enter value of n:");
  scanf("%d",&n);

  for(int i=0;i<n;i++)
  {
    printf("Person %d:\n",i+1);
    for(int j=0;j<n;j++)
    {
      printf("Job %d:\n",j+1);
      scanf("%d",&a[i][j]);
    }
    printf("\n");
  }

  int b[1000][n],c[n];
  for(int i=0;i<n;i++)
  {
    c[i]=i;
  }

  int row_in_b=permute(c,0,n-1,b);

  int min=10000000;
  int cost;

  for(int i=0;i<row_in_b;i++)
  {
    cost=0;
    for(int j=0;j<n;j++)
    {
      cost+=a[j][b[i][j]];
    }
    printf("%d\n",cost);
    printf("\n");
    if(cost<min)
    {
      min=cost;
    }
  }
  printf("Minimum is %d\n",min );
  return 0;
}